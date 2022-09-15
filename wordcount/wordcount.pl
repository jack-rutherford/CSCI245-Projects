use warnings;
use strict;

my $count = 0;
my @ARGV = ();
my $wordcount = 0;
my $file_ind = 0;
my @files = ();
my @badfiles = ();

print("Please enter in a search word:\n");
chomp(my $search_word = <>);

print("Enter the names of the files you want searched:\n");
chomp(@ARGV = <>);

if($#ARGV < 1){
    print "Usage: perl wordcount.pl search_word file1 file2 ... filen\n";
    exit -1;
}

=begin
# Three nested loops, one to go through each file in @ARGV
# one to split each line in the file into a new array: @lines
# and the third to go through each word in the line and add them
# to the word count if the word matches the search word
=cut
for(my $n = $count; $n<=$#ARGV; $n+=1){
    my $loc_wordcount = 0;
    if(!(-e $ARGV[$count])){
        push(@badfiles, $ARGV[$count]);
    }
    else{
        open(FH, $ARGV[$count]);
        chomp(my @lines = <FH>);
        for(my $i = 0; $i<$#lines+1; $i+=1){
            my @spl = split(' ',$lines[$i]);
            for(my $k = 0; $k < $#spl+1; $k+=1){
                if($spl[$k] eq $search_word){
                    $loc_wordcount++;
                }
            }
        }
        if($loc_wordcount > $wordcount){
            if(@files != 0){
                @files = ();
            }
            $wordcount = $loc_wordcount;
            push(@files, $ARGV[$count]);
        }
        elsif($loc_wordcount == $wordcount){
            push(@files, $ARGV[$count]);
        }
    }
    $count++;
}
# This is if no words in any files were found, print an error message
if($wordcount == 0){
    print "The word \"$search_word\" did not occur in any of the files examined\n";
    exit -1;
}
if(@badfiles != 0){
    my $str =  "The following files do not exist or could not be opened:";
    foreach my $ind (@badfiles){
        $str .= "\n* " . $ind;
    }
    print $str."\n";
}
# If there's more than 1 file with the same # of word count, print plural with all files
# Else print the singular form
if($#files > 0){
    my $str = "The largest number of times the word \"$search_word\" occurred was $wordcount, in the files:";
    foreach my $ind (@files){
        $str .= "\n* " .  $ind;
    }
    print $str."\n";
}
else{
    my $filename = $files[0];
    print "The largest number of times the word \"$search_word\" occurred was $wordcount, in the file $filename\n";
}
