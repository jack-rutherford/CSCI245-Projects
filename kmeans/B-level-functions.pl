#  This subroutine should print out the usage information shown in the assignment
#  description for the --help option.
sub printUsage () {
    print ("Usage:  perl kmeans-B.pl  --filename name [--datapoints=0]  [--centers=0]  [--groups=1]  [--help]\n");
    print("At least one of --datapoints, --centers, --groups must be true\n");
}

#  This subroutine takes a reference to an array of observations, where an observation
#  is a reference to a hash containing keys "label" and "values".  The value of the "label"
#  key is a string identifying the observation's label, and the value of the "values" key
#  is a reference to an array.
#
#  The routine should return a reference to a hash whose keys are the distinct labels
#  for the observation, and whose values are references to the observations having
#  that label.
sub createGroupsByLabel {
    #  Replace this hard coded hash reference with your implementation
    return {
        "Setosa" => [
            {
                "label" => "Setosa",
                "values" => [5.1, 3.5, 1.4, .2]
            },
                        {
                "label" => "Setosa",
                "values" => [4.9, 3, 1.4, .2]
            }
        ],        
        "Versicolor" => [
            {
                "label" => "Versicolor",
                "values" => [7,3.2,4.7,1.4]
            }
        ],
        "Virginica" => [
            {
                "label" => "Virginica",
                "values" => [6.3,3.3,6,2.5]
            }
        ]
    };
}

#  This routine takes a reference to an array of observations, and returns a reference
#  to an array whose components are the averages of the corresponding components for
#  the observations.
#
#  For example, if the "values" components of the observations contained the arrays 
#  (1, 4, 7), (2, 5, 8), and (3, 6, 9), the returned array would contain 
#  (1+2+3 = 6/3 = 2, 4+5+6 = 15/3 = 5, 7+8+9 = 24/3 = 8)
sub computeAverage {
    
}

#  This subroutine takes a reference to the hash produced by createGroupsByLabel
#  and prints out the information contained in that hash based on the specifications
#  in the assignment description.  Use the printObservation subroutine 
#  to print out each observation, and the computeAverage subroutine to compute the 
#  average of each group of observations.
sub printGroups {
    my @labels = readLabels($filename);
    my ($hashRef) = $_[0];
    my %hash = %$hashRef;
    print "There were ", scalar 
    print "Print groups called\n";
}

#  This line indicates the return status of "requiring" the file.  It should always be
#  a true value; don't modify or delete this line
1;
