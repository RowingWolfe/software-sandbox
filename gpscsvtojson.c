/*
    CSV to JSON could be very useful, though usually I would write a tool like this in python.
    Honestly really depressed and tired today so this doesn't work and my brain wont work with me to figure
    out why. This doesn't bode well.

    Guess I will try to rewrite it now.
*/

#include <stdio.h>

int main(){
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("data=[");
    while (scanf("%f,%f,%79[^\n", &latitude, &longitude, info) == 3) {
        if (started)
            printf(",\n");
        else 
            started = 1;

        if ((latitude < -90.0) || (latitude > 90.0)){
            fprintf(stderr, "Invalid latitude: %f\n", latitude);
            return 2;
        }
        if ((longitude < -180.0) || (longitude > 180.0)){
            fprintf(stderr,"Invalid longitude: %f\n", longitude);
            return 2;
        }

        printf("{latitude: %f, longitude %f, info: '%s}",latitude, longitude, info);
    }
    puts("\n]");
    return 0;
}

//Still doesn't work, still have no energy. Probably shouldn't be doing this but what else could I be doing right now?
// FFFFFFfuck it. Just gonna get through the chapter for today... maybe I come back and fix this. Maybe I don't.

