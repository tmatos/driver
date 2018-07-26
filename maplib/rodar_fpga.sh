#!/bin/bash

ARQUIVO_MEDIDAS=medidas_fpga.txt

# REALIZAR AS MEDIDAS (em microsegundos)

rm -f $ARQUIVO_MEDIDAS

for i in {1..10000} # repeticoes
do
    ./conv_fpga >> $ARQUIVO_MEDIDAS
done


# CALCULAR A MEDIA

count=0;
total=0; 

for i in $( awk '{ print $1; }' $ARQUIVO_MEDIDAS )
do 
    #total=$(echo $total+$i | bc )
    total=$(awk 'BEGIN { print ('$total'+'$i') }')
    ((count++))
done

echo "Media (us) ="
awk 'BEGIN { print ('$total'/'$count') }'
#echo "scale=2; $total / $count" | bc

#tftp -p -l $ARQUIVO_MEDIDAS 192.168.141.27

