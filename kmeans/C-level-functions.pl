#  This subroutine is passed a file handle representing an already 
#  opened file containing the data to be processed.  It should
#  - Read and chomp the first line from the file
#  - Delete any " characters from the line  (see the /d argument to the tr function)
#  - Split the line using a comma as the delimiter
#  - return the resulting array
sub readLabels {
    open (FH, $ARGV[0]) or die "The file does not exist -1";
    chomp(my $line = <FH>);
    $line =~ tr/"//d;
    return my @spl = split(",", $line);
}

#  This subroutine is passed one argument:
#  a reference to an array of strings from the input file, with each line 
#  being a single observation from the data set.  The line is a comma-separated
#  sequence of values.  The first n-1 values are measurements of some feature 
#  of the observation, while the last value is a label indicating the observation's
#  class.
#  The subroutine should return a reference to an array whose elements are 
#  references to hashes containing two keys:  "label" and "values".  The 
#  value for the "label" key is simply the last value on the line,
#  with any "" characters around the label having been removed
#  The value for the "values" key is a reference to an array containing the n-1
#  measurements
sub readObservations {
    my @returnArray = ();
    my ($arrayRef) = @_;     # Get array ref from parameter
    my @lines = @$arrayRef;  # Dereference array
    splice(@lines, 0, 1);
    for($i = 0; $i <= $#lines; $i++){
        my @line = split(",", $lines[$i]);
        my @values = ();
        my $label = $line[$#line];
        $label =~ tr/"//d;
        for(my $k = 0; $k < $#line; $k++){
            push(@values, $line[$k]);
        }
        my %data = (
            "label" => $label,
            "values" => \@values
        );
        push @returnArray, \%data;
    }
    return \@returnArray;
}

#  This subroutine is passed two arguments.
#  The first is a scalar reprenting an observation number
#  The second is a reference to a hash containing the keys
#  label and values.  The values of these keys is described in the 
#  documentation for the readObservations function above.
#  The function should print out the following information, all on 
#  a single line, with a new line character at the end
#  - the observation number
#  - a tab
#  - the label for the observation
#  - a space
#  - the values for the observation, in the format (x1, x2, ..., xn)
#  Note there is a space after each of the commas
#  A sample observation might look like this:
#  1       Setosa:(5.1, 3.5, 1.4, .2)
sub printObservation {
    print "$_[0]:\t";
    my ($hashRef) = $_[1];
	my %keyVal = %$hashRef;
    my ($valArrRef) = $keyVal{values};    
    my @valArr = @$valArrRef;  # Dereference array
    print "$keyVal{label}:($valArr[0], $valArr[1], $valArr[2], $valArr[3])\n";
}

#  This subroutine is passed 2 arguments:
#  A string containing the last line of the data file
#  A reference to the array of data points.
#
#  It should return a list containing 3 elements
#  Element 0:  a "boolean" indicating whether the cluster centers are valid
#  Element 1:  a string describing the reason the cluster centers are invalid, or 
#              the empty string if the centers were valid
#  Element 2:  a reference to an array containing the cluster center index values; this is a reference
#              to an empty array if an error condition is flagged
#
#  A cluster center index is invalid if 
#  -  it is less than 0 or greater than the largest valid index for the array referenced by the 2nd argument
#     In this case the error message should be in the form 
#     "Cluster center # is invalid; must be between 0 and #"
#
#  The function should also return false if a data point index is included in the list of cluster centers 
#  more than once.  In this case the error message should be in the form
#  Index # specified multiple times as a cluster center
sub readAndValidateClusterCenters {
    my $arrayRef = $_[1];
    my @dataPoints = @$arrayRef;
    my @points = split(",", $_[0]); # $_[0] = lastLine argument passed to sub
    my $flag = 1;
    my $EM = "";
    for($i = 0; $i <= $#points; $i++){
        if($points[$i] < 0 || $points[$i] > $#dataPoints){
            $EM += "Invalid Cluster Center: $points[$i]. Must be between 0 and $#dataPoints\n";
            $flag = 0;
        }
        for($j = 0; $j <= $#points; $j++){
            if($points[$j] == $points[$i] && ($j != $i)){

                $EM += "Index $points[$i] specified multiple times as a cluster center\n";
                $flag = 0;
            }
        }
    }
    if($flag != 0){
        return ($flag, $EM, \@points);
    }
    return ($flag, $EM, []);
}

#  This line indicates the return status of "requiring" the file.  It should always be
#  a true value; don't modify or delete this line
1;
