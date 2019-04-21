# Boilerplate-master (bpm)
A program that generates boilerplate files whenever you need.  

You can edit/add boilerplates here: ~/.bpm/boilerplates.  It's pretty straight forward.  
Feel free to open pull requests if the boilerplate is mandatory, but make sure to use this naming standard: .bpm/boilerplates/<language>/<boilerplate-name>.  
  
Examples:  
```
  .bpm/boilerplates/cpp/class
  .bpm/boilerplates/c/header
  .bpm/node/server
```

# Usage
Format:  

```
bpm <filename> <language> <boilerplate>
```  

Example:  

```
bpm main.c c main
```  

Generates the file ```main.c``` with the content of [this boilerplate](https://github.com/MarcelKaemper/boilerplate-master/blob/master/boilerplates/c/main)


# Installation
```
git clone https://www.github.com/marcelkaemper/boilerplate-master
gcc main.c -o bpm
sh setup.sh
```

To make this program executable from every location you can either use an alias:  
```
alias bpm="path/to/executable"
```  
Or copy/move it to /usr/bin/ :
```
sudo cp bpm /usr/bin/bpm
