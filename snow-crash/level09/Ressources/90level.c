#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av)
{
        int fd;
        int i;
        char buf[1];
        char c;

        i = 0;
        fd = open(av[1], O_RDONLY);
        while(i < 25)
        {
								read(fd, &buf, 1);
                c = (unsigned char)(buf[0] - i);
                write(1, &c, 1);
                i++;
        }
        write(1, "\n", 1);
        return (0);
}
