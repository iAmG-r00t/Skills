# C strings & `/proc`

- For the first objectivem it's mainly to learn how to use the linux ***procss information pseudo-filesystem*** [`/proc`](https://tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html) that is also a virtual filesystem, to find and modify variables contained inside the virtual memory of a running process, and learn some cool things along the way.

## Resources

- [holberton Part 1](https://github.com/holbertonschool/Hack-The-Virtual-Memory/tree/master/00.%20C%20strings%20%26%20the%20proc%20filesystem)
- [Introduction to memory management in Linux](https://www.youtube.com/watch?v=7aONIVSXiJ8)
- [Virtual Memory Youtube Playlist](https://www.youtube.com/playlist?list=PLiwt1iVUib9s2Uo5BeYmwkDFUh70fJPxX)

---

- [The main file](./main.c) contains the C code for this first objective, please visit the resources section; *holberton part 1* to follow along.
	- Compile the code this way: `gcc -Wall -Wextra -pedantic -Werror main.c -o loop`
	- Run the compiled program `loop` and then execute this to look into the program inside the `/proc` folder: `ps aux | grep -m 1 loop | cut -d' ' -f5 | xargs -I % ls -la /proc/%/`
	- Do note that if you are following along with the resource from holberton, they state that the **PID** will keep changing but on my end I have noticed it is not changing because the program is running in a loop hence the process ID is still the same until you end the process.

	![image](https://user-images.githubusercontent.com/29776892/129325840-2f4e2a29-21cc-4d9b-b591-b67b8ac43244.png)
