use strict;
use warnings;

my %amino_acids = ('A' => 0, "C" => 0, 'D' => 0, 'E'=> 0, 'F'=> 0, 'G'=> 0, 'H'=> 0, 'I'=> 0, 'K'=> 0, 
                     'L'=> 0, 'M'=> 0, 'N'=> 0, 'P'=> 0, 'Q'=> 0, 'R'=> 0, 'S'=> 0, 'T'=> 0, 'V'=> 0, 'W'=> 0, 'Y'=> 0);

open(FH, $ARGV[0]) or die "The file does not exist -1";
chomp(my @lines = <FH>);
splice(@lines, 0, 1);

foreach my $aa(@lines){
    my @spl = split('', $aa);
    foreach my $str(@spl){
        if(exists($amino_acids{$str})){
            $amino_acids{$str} = $amino_acids{$str}+1;
        }
    }
}
foreach my $key (sort keys %amino_acids)
{
  print "$key: $amino_acids{$key}\n";
}