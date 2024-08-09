/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:28:07 by tboussad          #+#    #+#             */
/*   Updated: 2024/08/09 17:09:34 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*struct sigaction {
    void (*sa_handler)(int);  Signal handler 
    void (*sa_sigaction)(int, siginfo_t *, void *); Alternate signal handler 
    sigset_t sa_mask;         Signal mask 
    int sa_flags;             Flags 
    void (*sa_restorer)(void); Restorer function
};*/

void	*ft_memset2(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void signals_handler(int sig)
{
    if (sig == SIGINT)
    {
        printf("\nReceived SIGINT\n");
        // rl_on_new_line();
        // rl_replace_line("", 0);
        // rl_redisplay();
    }
    else if (sig == SIGQUIT)
        printf("\nReceived SIGQUIT\n");
}

void mask_and_catch_signals(t_sigaction *sig)
{
    sig->sa_handler = signals_handler;

    //to use only in the signals collision
    // sig->sa_flags = SA_RESTART; // Restart interrupted system calls
    
    sigemptyset(&sig->sa_mask);
    sigaddset(&sig->sa_mask, SIGINT);
    sigaddset(&sig->sa_mask, SIGQUIT);
    sigaction(SIGINT, sig, NULL);
    sigaction(SIGQUIT, sig, NULL);
}

void init_sigaction()
{
    t_sigaction sig;

    ft_memset2(&sig, 0, sizeof(sig));
    mask_and_catch_signals(&sig);
}

/*int main() {
    char *line;

    init_sigaction();

    while ((line = readline("> ")) != NULL) {
        // Process the input line
        // add_history(line);
        free(line);
    }

    printf("Exiting shell\n");

    return 0;
}*/

/*int main()
{
    char buffer[10];
    // t_sigaction sig; // Assuming t_sigaction is a defined struct

    // Test ft_memset2
    ft_memset2(buffer, 'a', sizeof(buffer));
    printf("Buffer: %s\n", buffer);

    // Initialize signal handling
    init_sigaction();

    // Simulate user input or other operations
    while (1) {
        // Your shell logic or other operations here
        sleep(1); // Simulate some work
    }

    return 0;
}*/

/*void	signals_handler(int sig, siginfo_t *siginfo, void *ptr)
{
	(void) ptr;
	(void) siginfo;
	if (sig == SIGINT)
	{
		if (g_data.shell_state != SH_READING)
			return ;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_data.exit_status = 1;
	}
}

}*/
