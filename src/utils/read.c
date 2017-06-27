/*
** read.c for 42sh in /Users/arthur/Documents/Dev/B2/PSU/PSU_2016_42sh/src/utils/
**
** Made by Arthur Chaloin
** Login   <arthur.chaloin@epitech.eu>
**
** Started on  Tue May  2 17:19:09 2017 Arthur Chaloin
** Last update Tue May  2 17:37:32 2017 Arthur Chaloin
*/
#include <unistd.h>
#include <sys/ioctl.h>
#include <term.h>

void	set_read_mode(int mode)
{
  static struct termios	termsave;
  static struct termios	term;

  if (mode == 1)
    {
      tcgetattr(0, &term);
      termsave = term;
      term.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(0, TCSANOW, &term);
    }
  else
    tcsetattr(0, TCSANOW, &termsave);
}
