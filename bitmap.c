//bitmap.c
#include "bitmap.h"
#include<stdio.h> 
#include<stdlib.h>

ProjectImage_t* project_readBitmapFile(const char* fileName){
	FILE *fpr=fopen(fileName,"rb"); 
	ProjectImage_t *INFORMATION;
	INFORMATION=malloc(sizeof *INFORMATION);

	fread(INFORMATION,sizeof(*INFORMATION),1,fpr);
	

	printf("\nWidth: %d\n",INFORMATION->width);
	printf("Height: %d\n",INFORMATION->height);
	printf("No. of bit per pixel: %d\n",INFORMATION->bitsPerPixel);
	//printf("Image size %d",INFORMATION->imgSize);
fclose(fpr);
return INFORMATION;
}


int project_writeBitmapFile(ProjectImage_t* image,const char* fileName){

	
	FILE *fp=fopen(fileName,"rb"); 
	fread(image,sizeof(*image),1,fp);

	FILE *fpw=fopen("Output.bmp","wb");
	fwrite(image,sizeof(*image),1,fpw);
	//fseek(fp,image->n[11],SEEK_SET);                          //offset
	int i;
	int *arr=(int*)malloc(image->imgSize*sizeof(int));       
	for(i=0;i<image->imgSize;i++){
	arr[i]=fgetc(fp);}
	
	for(i=0;i<100;i++){printf("%d\n",arr[i]);}   //display data
		
	for(i=0;i<image->imgSize;i++){
	fputc(arr[i],fpw);
	}
	
	free(arr);
	fclose(fp);
	fclose(fpw);
	
}

int freeImage(ProjectImage_t* image){
	free(image);
}


