echo Running setup
echo Creating config file ~/.bpmconfig
touch ~/.bpmconfig
pwd >> ~/.bpmconfig
echo Setup successful
echo Cleaning up
rm ./setup.sh
