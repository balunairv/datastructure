read user
if who|grep $user>/dev/null
then 
	echo "$user is logged into the system" 
else
	echo "$user is not logged into the system" 
fi
