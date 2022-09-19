#  Jack Rutherford and Justin Fay

use strict;
my $include_oxford_comma = 0;
my $first_name = "";
my $last_name = "";
my $foods = "";
my @foods = ();

#  Determine if there are 1 or more command line arguments; if there 
#  are, decide whether the value of the first argument is the string "--true"
if (@ARGV == 1) {
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

print "Please enter your three favorite foods, one per line\n";
chomp ($foods[0] = <>);
chomp ($foods[1] = <>);
chomp ($foods[2] = <>);

#  Insert the word "and" into the list of foods, so the user doesn't have 
#  to type it
($foods[2], $foods[3]) = ("and", $foods[2]);


#  Using the oxford comma means that we should have a comma after each word in the list
if ($include_oxford_comma) {
	$foods = join (", ", @foods);
}
else {
	$foods = join (", ", ($foods[0], $foods[1]));
	$foods .= " and " . $foods[3];
}


print "You are $first_name $last_name, and you like to eat $foods!\n";
