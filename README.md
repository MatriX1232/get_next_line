
# Get Next Line

A 42 project called GetNextLine




![100%](https://github.com/MatriX1232/get_next_line/blob/main/Screenshot%20from%202024-06-17%2016-41-11.jpg)


## Run Locally

Clone the project

```bash
  git clone https://github.com/MatriX1232/get_next_line.git
```

Go to the project directory

```bash
  cd get_next_line
```

Run Makefile

```bash
  make
```


## Usage/Examples

```c
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int	fd = open("test.txt", O_RDONLY);
	for(int i=0; i < 10; i++)
	{
		char	*line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
```


## License

[MIT](https://choosealicense.com/licenses/mit/)

