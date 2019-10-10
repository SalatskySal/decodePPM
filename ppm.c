/** ppm.c
Reseni IJC-DU1, priklad b), 20.03.2019
Autor: Serhii Salatskyi, FIT
Prelozeno gcc 7.3.0
Modul pro otevreni obrazku formatu .ppm a scitani dat z neho
*/

#include "ppm.h"

struct ppm * ppm_read(const char *filename)
{
    char buff[16];
    ppm *img;
    FILE *fp;
    int rgb_comp_color;
    //open PPM file for reading
    fp = fopen(filename, "rb");
    if (!fp) {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
         exit(1);
    }

    //read image format
    if (!fgets(buff, sizeof(buff), fp)) {
         perror(filename);
         exit(1);
    }

    //check the image format
    if (buff[0] != 'P' || buff[1] != '6') {
         fprintf(stderr, "Invalid image format (must be 'P6')\n");
         exit(1);
    }

    //alloc memory form image
    img = (ppm*)malloc(sizeof(ppm));
    if (!img) {
         fprintf(stderr, "Unable to allocate memory\n");
         exit(1);
    }

    //read image size information
    if (fscanf(fp, "%u %u", &img->xsize, &img->ysize) != 2) {
	 fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
	 ppm_free(img);
         exit(1);
    }

    //read rgb component
    if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
         fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
         ppm_free(img);
	 exit(1);
    }

    //check rgb component depth
    if (rgb_comp_color!= 255) {
         fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
         ppm_free(img);
	 exit(1);
    }

    img->data = (unsigned char*)malloc(img->xsize * img->ysize*3*sizeof(char*));

    //read pixel data from file
    if (fread(img->data, 3 * img->xsize, img->ysize, fp) != img->ysize) {
         fprintf(stderr, "Error loading image '%s'\n", filename);
         exit(1);
    }

    fclose(fp);
    return img;
}

void ppm_free(ppm* p){
	free(p->data);
	free(p);
}
