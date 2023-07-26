# Build System and Memory Manipulation - Simple Embedded Practice Project
(Coursera embedded course Module1 Final Assessment)

## Using Makefile Example
- For HOST machine(x86):
```bass 
   	make build COURSE1=COURSE1 PLATFORM=HOST
```
- For TI MSP432P401R:
```bass
	make build COURSE1=COURSE1 PLATFORM=MSP432
``` 
- With more verbosity: 
```bass
	make build COURSE1=COURSE1 PLATFORM=MSP432 VERBOSE=VERBOSE
```
