use strict;
use warnings;

my $odd_occ = 0;
my @dif_acids = ();
my %amino_acids = ('A' => 0, "C" => 0, 'D' => 0, 'E'=> 0, 'F'=> 0, 'G'=> 0, 'H'=> 0, 'I'=> 0, 'K'=> 0, 
                     'L'=> 0, 'M'=> 0, 'N'=> 0, 'P'=> 0, 'Q'=> 0, 'R'=> 0, 'S'=> 0, 'T'=> 0, 'V'=> 0, 'W'=> 0, 'Y'=> 0);

open(FH, $ARGV[0]) or die "The file does not exist -1";
chomp(my @lines = <FH>);
splice(@lines, 0, 1);

# Go through each line of file and count amino acids
foreach my $aa(@lines){
    my @spl = split('', $aa);
    foreach my $str(@spl){
        if(exists($amino_acids{$str})){
            $amino_acids{$str} = $amino_acids{$str}+1;
        }
        else{
            $odd_occ++;
            push(@dif_acids, $str);
            for(my $i = 0; $i < $#dif_acids; $i++){
                if($str eq $dif_acids[$i]){
                    pop(@dif_acids);
                }
            }
            
        }
    }
}

# Print number of amino acids and how many occurrences
foreach my $key (sort keys %amino_acids)
{
  print "$key: $amino_acids{$key}\n";
}

if(scalar @dif_acids != 0){
    @dif_acids = sort @dif_acids;
    print "Number of different amino acids: $odd_occ\n";
    my $response = "";
    if($#dif_acids <= 1){
        $response = join (" or ", @dif_acids);
    }
    else{
        my $count = 0;
        $count = scalar @dif_acids;
        ($dif_acids[$count - 1]) = ("or ".$dif_acids[$count - 1]);
        $response = join (", ", @dif_acids);
        
    }
    # join (", ", ($dif_acids[0], $dif_acids[1]));
    # $response .= " " . $dif_acids[-2];
    print "No occurrences of $response\n";
}
