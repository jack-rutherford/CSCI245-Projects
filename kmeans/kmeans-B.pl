use strict;
use Getopt::Long;

require "./C-level-functions.pl";
require "./B-level-functions.pl";

#  Variables to hold the results of the command line options
#  TODO:  Initialize these variables to the appropriate defaults
my $filename   = "";
my $datapoints = -1; # 0
my $centers = -1; # 0
my $groups = -1; # 1
my $help = -1;
my $flag = 0;

#  TODO
#  Make a call to GetOptions to parse the command line arguments
#  based on the requirements described in the assignment specification
#  Store the results into the variables defined above
GetOptions(
  "filename=s", \$filename,
  "datapoints:i", \$datapoints,
  "centers:i", \$centers,
  "groups:i", \$groups,
  "datapoints!", \$datapoints,
  "centers!", \$centers,
  "groups!", \$groups,
  "help!", \$help
);

# TODO  Check if the --help option was specified.  If it was, call the
# subroutine printUsage and then exit with a status of 0
# check help? if something
if($help == 0){
  print "\"--nohelp\" not a valid input\n";
  printUsage();
  exit 0;
}
if($help == 1){
  print "help called";
  printUsage();
  $help = "";
  exit 0;
}


#  TODO
#  Write a statement that verifies that a value has been provided for the
#  --filename command line argument, and that at least one of the
#  --datapoints, --centers, and --groups arguments have been specified
#  If not, the program should call printUsage and then exit with a status of 1
if($datapoints < 0){
  $datapoints = 0;
  $flag = 1;
}
elsif($datapoints <= 0){
  $datapoints = 0;
}
if($centers < 0){
  $centers = 0;
  $flag = 1;
}
elsif($centers <= 0){
  $centers = 0;
}
if($groups < 0){
  $groups = 1;
  $flag = 1;
}
elsif($groups <= 0){
  $groups = 1;
}

if($filename eq "" || (($datapoints == 0 && $centers == 0 && $groups == 1)) && $flag == 0){
  printUsage();
  exit 1;
}

my $datafile;

unless ( open $datafile, $filename ) {
    print "Cannot open $filename\n";
    exit 2;
}

my @labels = readLabels($datafile);

my $line       = "";
my @datapoints = ();
chomp( my @lines = <$datafile> );

my @observations       = @lines[ 0 .. $#lines - 1 ];
my $datapointsArrayRef = readObservations( \@observations );

@datapoints = @$datapointsArrayRef;

my $valid = 1;
my $error = "";
my $clusterCentersArrayRef;

( $valid, $error, $clusterCentersArrayRef ) =
  readAndValidateClusterCenters( $lines[-1], $datapointsArrayRef );

if ( !$valid ) {
    print "ERROR: $error\n";
    exit 3;
}

my $i = 1;
print "There were ", scalar @datapoints,
  " observations in the file, consisting of ", scalar @labels - 1,
  " features\n";

#  TODO  Make sure the data points are only displayed when the --datapoints argument
#  has been specified
if($datapoints > 0){
  for my $datapointRef (@datapoints) {
      printObservation( $i, $datapointRef );
      $i++;    
  }
}
my @clusterCenters = ();

@clusterCenters = @$clusterCentersArrayRef;

#  TODO Make sure the text "Cluster centers" and the datapoints chosen as the
#  cluster centers are only displayed when the --centers argument has been specified
if($centers > 0){
  print "\nCluster centers\n";
  for my $clusterCenterIndex (@clusterCenters) {
      printObservation( $clusterCenterIndex,
          $datapoints[$clusterCenterIndex] );
  }
}

#  TODO  Make sure the groups are printed only when the --groups argument is true
if($groups >= 1){
  my $groupsRef = createGroupsByLabel( \@datapoints );
  printGroups($groupsRef);
}
