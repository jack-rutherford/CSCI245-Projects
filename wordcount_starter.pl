#Ryan and Jack

#!/usr/bin/perl -w
use strict;

my @words; 

#  Check to make sure that the number of command line arguments
#  in the ARGV array is at least 1; if not, print out an error message
#  and die
if (@ARGV < 1) {
	print("You must specifiy the name of the file to open");
	die;
}

#  Open the file specified by the file in the first element of the ARGV
#  array; if this fails, print out an error message and die
#  First argument to open is a filehandle to be used later; second is 
#  the name of the file to be opened

open (FH, $ARGV[0])
	or print("File could not be opened.\n"), die;
	

#  Read all of the lines in the document into an array named @lines
chomp (my @lines = <FH>);


#  Declare an initially empty hash named wordcounts
my %wordcounts = ();

#  Iterate over the lines in the file
foreach (@lines) {
	chomp($_);
	#  Convert any upper case letters to lower case
	$_ =~ tr/A-Z/a-z/;

	#  Convert any non letters into spaces; the c at the end of the 
	#  tr operator causes the search list (the first blank) to be 
	#  complemented
	#$_ =~ tr/!-\/, :-@, [-`, {-~/ /c;
	$_ =~ s/[[:punct:]]//g;

	#  Use split to break the line up by spaces and put 
	#  the result into an array named @words
	foreach my $word (split(' ', $_)) {
		# print("$word \n");
		push(@words, $word);
	}
	
	
	#my @words = split(" ", @lines);

	#  Iterate over the words in @words, and increment the number of times
	#  that each have been seen

	
 
	foreach my $word(@words) {
		if(exists $wordcounts{$word}) {
			# print($word);
			$wordcounts{$word} = $wordcounts{$word}+1;
		} else {
			$wordcounts{$word} = 1;
		}
		

	}
	@words = ();
}

#  Sort the stored counts in descending order, storing the result
#  in an array
#  The first blank is an anonymous function that sort will use to compare 
#  two elements from the list being sorted.  The values being compared can 
#  be referenced within this function as the scalars $a and $b.
my @descending_values = sort {lc $b cmp lc $a} values %wordcounts;

#  Figure out the boundary number of occurrences that should be skipped,
#  if any, by looking for a second command line argument

#  Iterate over the words in the hash (sorted alphabetically), and print
#  them out (possibly skipping words that occur too frequently)

# foreach my $key (sort keys %wordcounts ) {
foreach my $key (sort keys %wordcounts){
    print "  $key $wordcounts{$key}\n";
}
my $numOfUnqWords = scalar keys %wordcounts;
$numOfUnqWords = $numOfUnqWords-1;
print "Total number of unique words seen was $numOfUnqWords";


#  Print the total number of unique words that were seen in the document
print("\n	\n");




if($ARGV[1] != 0) {
	print $ARGV[1]." words were skipped\n";
	my @sortedWords = ();

	foreach my $key (sort {$wordcounts{$b} <=> $wordcounts{$a}} keys %wordcounts){
		# print "  $key $wordcounts{$key}\n";
		push(@sortedWords, $key);
	}

	splice(@sortedWords, 0, $ARGV[1]);

	foreach my $word (@sortedWords) {
		print( "$word: $wordcounts{$word} \n");
	}
}


