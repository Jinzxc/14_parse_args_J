#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *buffer[5];

char **parse_args(char *line) {
    char *p = line;

    int i = 0;
    while(p) {
        buffer[i] = strsep(&p, " ");
        i++;
    }

    return buffer;
}

int main(int argc, char *argv[]) {
    char line[] = "ls -a -l";
    char **args = parse_args(line);

    /*
    uncomment these lines at your own risk
    char starwars_EpisodeIV[] = "nc towel.blinkenlights.nl 23";
    char **movie = parse_args(starwars_EpisodeIV);
    execvp(movie[0], movie);
    */

    execvp(args[0], args);
    return 0;
}