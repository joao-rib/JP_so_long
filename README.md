# JP_so_long
This project takes a simple matrix (in .ber format) made up of specific characters, and converts it into a simple rudimentary game about finding collectibles. The sprites used for this project (with one exception), were found in a public database. 

## General notes

### Functions from existing libraries
Functions from `signal.h` may require further context. It is recommended to read up on the structures behind them.

Function | Format | Description | Library
--- | --- | --- | ---
getpid | `int	getpid(void)` | Returns the current process ID | `signal.h`
kill | `int	kill(int pid, int sig)` | Sends signal sig to process pid. Returns 0 on success, -1 on error | `signal.h`
sigaction | `int	sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)` | Change action from a process based on the receipt of signal signum, according to either act or oldact. Returns 0 on success, -1 on error | `signal.h`
sigemptyset | `int	sigemptyset(sigset_t *set)` | Initializes and empties a signal set. Returns 0 on success, -1 on error | `signal.h`
pause | `int	pause(void)` | Pauses execution until a signal is delivered | `unistd.h`
sleep | `unsigned int	sleep(unsigned int s)` | Suspends execution for s seconds. Returns 0 (if interrupted, returns remaining time). | `unistd.h`
usleep | `int	usleep(unsigned int usec)` | Suspends execution for usec microseconds. Returns 0 (if interrupted, returns remaining time). | `unistd.h`

## Main Functions

### Libft functions

Function | Format | Modified?
--- | --- | ---
ft_strnstr | `char	*ft_strnstr(const char *big, const char *little, size_t len)` | Same as libft
ft_strtrim | `char	*ft_strtrim(const char *s1, const char *set)` | Same as libft
ft_strlcpy | `size_t	ft_strlcpy(char *dest, const char *src, size_t size)` | Same as libft
ft_calloc | `void	*ft_calloc(size_t nmemb, size_t size)` | Same as libft
ft_memset | `void	*ft_memset(void *s, int c, size_t n)` | Same as libft
ft_strdup | `char	*ft_strdup(const char *src)` | Same as libft
ft_itoa | `char	*ft_itoa(int n)` | Same as libft
ft_strjoin | `char	*ft_strjoin(const char *s1, const char *s2)` | Same as libft
ft_printf | `int	ft_printf(const char *string, ...)` | Same as ft_printf
ft_putchar_fd | `int	ft_putchar_fd(char c, int fd)` | Same as ft_printf
ft_putstr_fd | `int	ft_putstr_fd(char *str, int fd)` | Same as ft_printf
ft_putnbr_fd | `int	ft_putnbr_fd(long n, int fd)` | Same as ft_printf
ft_strlen | `size_t	ft_strlen(const char *str)` | Same as libft
ft_putnbr_ubase_fd | `int	ft_putnbr_ubase_fd(unsigned int nbr, char *base, int fd)` | Same as ft_printf
ft_putnbr_lbase_fd | `int	ft_putnbr_lbase_fd(unsigned long nbr, char *base, int fd)` | Same as ft_printf
ft_strchr | `char	*ft_strchr(const char *str, int c)` | Same as get_next_line
get_next_line | `size_t	ft_strlcat(char *dest, const char *src, size_t size)` | Same as get_next_line
ft_strlcat | `size_t	ft_strlcat(char *dest, const char *src, size_t size)` | Same as get_next_line
ft_strbuild | `char	*ft_strbuild(char *s1, const char *s2)` | Same as get_next_line

### New functions

Function | Format | Description | Return
--- | --- | --- | ---
flood_fill | `void	flood_fill(char **tab, t_point size, t_point begin)` | Replaces multiple characters of tab with "F" in a flood pattern, starting with begin. Only affects input size | -
ft_strarrdup | `char	**ft_strarrdup(char **src)` | Creates new string array as a duplicate of src [requires malloc] | New string array
ft_strchr_pos | `int	ft_strchr_pos(const char *str, int c)` | Returns position of first instance of char c in str (if c is not found, returns -1) | Position of c in str, or -1
flood_fill_sl | `void	flood_fill_sl(char **tab, t_point size, t_point begin)` | Modified version of flood_fill, as to better fit the scope of so_long | -

### Specific functions

Type | Function | Format | Description
--- | --- | --- | ---
Error Handling | error_msg | `int	error_msg(char *msg)` | Prints str as an error message, without exiting the program
Error Handling | error_exit | `void	error_exit(char *msg, t_game *g)` | Prints an error message, destroys game and map, then exits the program
Error Handling | error_map | `void	error_map(char *msg, t_game *g)` | Prints an error message, destroys only the map, then exits the program
Destroying | destroy_map | `void	destroy_map(t_game *g)` | Frees every necessary variable in the s_map structure (including itself)
Destroying | destroy_game | `int	destroy_game(t_game *game)` | Frees every possible variable within the s_game structure
Loading | load_map | `void	load_map(t_game *g, char *file)` | Loads the map information, contained in a .ber file, into an s_map structure
Loading | load_graphics | `void	load_graphics(t_game *g)` | Initializes the mlx and win variables into an s_display structure, using MiniLibX functions
Loading | load_sprites | `void	load_sprites(t_game *g, int nsprites)` | Creates an array of s_sprite structures, containing information from their respective .xpm files, using a MiniLibX function
Rendering | render_map | `void	render_map(t_game *g)` | Renders the loaded map into the game window upon start, using MiniLibX functions
Rendering | render_movement | `int	render_movement(t_game *g)` | Renders player movement, using MiniLibX functions
Moving | move_handler | `int	move_handler(int keypress, t_game *g)` | Handles the consequences of each key press
Moving | move_player | `void	move_player(t_game *g)` | Handles various consequences derived from player movement
Other | validate_map | `void	validate_map(t_game *g)` | Verifies whether the loaded map fulfills several parameters (for example, map must be winnable)


