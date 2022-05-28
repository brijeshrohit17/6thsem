#Brijesh Rohit
#U19CS009

idle=$(top -bn2 | grep '%Cpu' | tail -1 | grep -P '(....|...) id,'| awk '{print $8}')
total=`echo "100.0 - $idle" | bc`
high=70.0
low=30.0
echo "CPU Usage: $total%"
if [ $(echo "$total >= $high" | bc) -eq 1 ]; then
echo "Overloaded "
elif [ $(echo "$total <= $low" | bc ) -eq 1 ]; then
echo "Lightly Loaded"
else
echo "Moderately Loaded"
fi