echo Running setup
echo Creating directory ~/bpm/
mkdir ~/.bpm/
mkdir ~/.bpm/boilerplates
echo Copying help
cp ./help ~/.bpm/help
echo Copying default boilerplates
cp -r ./boilerplates/* ~/.bpm/boilerplates/
echo Setup successful
echo Cleaning up
