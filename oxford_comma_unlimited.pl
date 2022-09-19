#  Jack Rutherford and Justin Fay

use strict;
my $include_oxford_comma = 0;
my $first_name = "";
my $last_name = "";
my $foods = "";
my @foods = ();

my $count = 0;

#  Determine if there are 1 or more command line arguments; if there 
#  are, decide whether the value of the first argument is the string "--true"
if (@ARGV >= 1) {
  if ($ARGV[0] eq "--true") {
    $include_oxford_comma = 1;
    shift @ARGV;
  }
  else {
    $include_oxford_comma = 0;
    #  A preview of what's to come; this checks to see if $ARGV[1] starts with --
    if ($ARGV[1] =~ /^--/) {
      shift @ARGV;
    }
  }  
}
else {
	#  No command line argument means that we will not use the oxford 
	#  comma
	$include_oxford_comma = 0;
}

if ($include_oxford_comma) {
  print "The Oxford comma IS being used\n";  
}
else {
  print "The Oxford comma IS NOT being used\n";
}

#  Get the input from the user
print "What is your first name? ";
chomp ($first_name = <>);

print "What is your last name? ";
chomp ($last_name = <>);

print "Please enter your favorite foods, one per line\n";
print "Enter 'Control d' to escape\n";
chomp (@foods = <>);
$count = @foods;

#  Insert the word "and" into the list of foods, so the user doesn't have 
#  to type it
if($count > 1)
{
    ($foods[$count - 1]) = ("and ".$foods[$count - 1]);
}


  #  Using the oxford comma means that we should have a comma after each word in the list
  if ($include_oxford_comma) {
    if($count > 2){
      $foods = join (", ", @foods);
    }
    else{
      $foods = join (" ", @foods);
    }
  }
  else {
    $foods = join (", ", ($foods[0], $foods[1]));
    $foods .= " " . $foods[-2];
  }


print "You are $first_name $last_name, and you like to eat $foods!\n";
