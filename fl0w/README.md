## Challenge Description

After a fierce pirate battle with another pirate ship, tuffy went to loot the other ship's treasures.
he found a file with the hint **Dont go with flow**. Help him crack it and loot the wrecked ship.

## Writeup

Analyse the binary in IDA and check the flow of the program. We can see there is a compare statement with a string.

![iamge1](assets/image1.png)

Load the binary in gdb, and disassemble the main function. We can see that it is skipping the middle block if the condition is invalid. So we will open the gdb to override the if condition manually. Below is the disassembly of the main function.

![image2](assets/image2.png)

We set a breakpoint at `0x00401622` and change the ```eax``` register to 0, to force the strcmp to be true. This will print the flag.

![image3](assets/image3.png)

### Author
[**InimicalX**](https://github.com/Akhil2193)