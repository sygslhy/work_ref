/*
 * main.c
 *
 *  Created on: 17 mars 2018
 *      Author: Administrator
 */

#include <stdint.h>
#include <stdio.h>

static uint8_t yuv_test_buf[16*16+8*8+8*8] = {
	250, 251, 252, 253, 254, 255, 255, 254, 253, 252, 251, 250, 177, 167, 100, 188,
	255, 255, 255, 255, 199, 187, 150, 111, 88,  199, 222, 255, 211, 107, 99, 76,
	251, 255, 255, 255, 199, 187, 150, 111, 88,  129, 222, 255, 211, 107, 98, 70,
	25,  255, 255, 255, 199, 18, 150, 111, 88,   139, 222, 255, 211, 107, 99, 76,
	27, 75, 255, 255,  193, 187, 150, 110, 88,   119, 222, 251, 211, 128, 97, 71,
	255, 255, 15, 255, 199, 186, 150, 111, 80,   109, 222, 255, 211, 107, 9 , 76,
	250, 251, 252, 253, 254, 255, 255, 254, 253, 252, 251, 250, 177, 167, 100, 188,
	25,  255, 255, 225, 199, 48, 150, 101, 88,   177, 222, 255, 211, 107, 99, 76,
	252, 75, 255, 255, 191, 187, 150, 110, 82,   119, 222, 254, 211, 128, 97, 71,
	20, 251, 252, 253, 250, 255, 255, 254, 253,  252, 251, 250, 157, 167, 100, 188,
	217, 255, 255, 255, 196, 187, 150, 111, 88,  199, 222, 255, 11, 107, 99, 76,
	250, 251, 252, 253, 254, 255, 255, 254, 253, 252, 251, 250, 177, 167, 100, 188,
	253, 255, 255, 255, 188, 187, 150, 111, 86,  199, 222, 255, 210, 107, 99, 76,
	251, 255, 255, 255, 199, 187, 150, 111, 88,  129, 222, 255, 211, 107, 98, 70,
	25,  255, 255, 255, 199, 18, 150, 111, 88,   139, 222, 255, 211, 107, 99, 76,
	250, 251, 252, 253, 254, 255, 255, 254, 253, 252, 251, 250, 177, 167, 100, 188,

	166, 188, 187, 244, 190, 90, 78, 122, 161, 118, 117, 245, 191, 90, 78, 122,
	199, 222, 255, 11, 107, 99, 76, 89, 197, 221, 252, 111, 117, 89, 76, 89,
	253, 252, 251, 250, 177, 167, 100, 188, 213, 52, 25, 150, 77, 127, 101, 128,
	199, 222, 255, 211, 107, 99, 76, 170, 129, 122, 155, 111, 207, 199, 176, 170,
	177, 222, 255, 211, 190, 99, 76, 99, 77, 122, 155, 11, 19, 199, 176, 199,
	139, 222, 255, 211, 107, 99, 76, 38, 138, 221, 215, 201, 117, 190, 86, 30,
	20, 251, 252, 253, 250, 255, 255, 254, 120, 51, 252, 153, 150, 155, 250, 254,
	119, 222, 255, 211, 128, 97, 71, 88, 111, 122, 155, 11, 228, 77, 171, 68
};

uint8_t rgb888_buf[8*8*3];

uint8_t rgb565_buf[8*8*2];
#define NORM_CB_CR(a) ((a)-(128))
void yuv420torgb888(  uint8_t* yuv_buf
					, uint8_t* rgb_buf
					, uint32_t yuv_w
					, uint32_t yuv_h
					, uint32_t rgb_w
					, uint32_t rgb_h
				)
{
	uint32_t subsamplingH_Y = yuv_w/rgb_w;       // detect the subsampling factor horizontal of Y
	uint32_t subsamplingV_Y = yuv_h/rgb_h;       // detect the subsampling factor vertical of Y
	uint32_t subsamplingH_UV = subsamplingH_Y/2; // detect the subsampling factor horizontal of UV : subsampling factor UV is Y/2 because of YCC420
	uint32_t subsamplingV_UV = subsamplingV_Y/2; // detect the subsampling factor vertical of UV
	uint8_t  rgb_bytes  = 3;  //rgb has 24=3x8bits

	uint32_t y_w = yuv_w;
	uint32_t y_h = yuv_h;
	uint32_t uv_w = yuv_w / 2; // uv width is half of y width

	uint8_t* ptr_Y  = yuv_buf;
	uint8_t* ptr_Cb = yuv_buf + y_w*y_h; //CbCr buffer is interleaved and is after Y buffer,  UV data pattern: UVUVUVUVUV
	uint8_t* ptr_Cr = ptr_Cb + 1;
	uint8_t  pixel_r, pixel_g, pixel_b;
	uint8_t* ptr_rgb = rgb_buf;

	for(int j=0; j<rgb_h; j++){
		// when a line is subsampled, we should jump to new line to sample, here we skip directly the lines which don't need to scan.
		ptr_Y  = yuv_buf + j* y_w * subsamplingV_Y;
		ptr_Cb = yuv_buf + y_w*y_h + j * uv_w * 2 * subsamplingV_UV;
		ptr_Cr = yuv_buf + y_w*y_h + 1 + j * uv_w * 2 * subsamplingV_UV;
		for (int i=0; i<rgb_w*rgb_bytes; i+=rgb_bytes){
			// convert the yuv data to rgb in 8bit.
			pixel_r = *ptr_Y + NORM_CB_CR(*ptr_Cr) + (NORM_CB_CR(*ptr_Cr)>>2) + (NORM_CB_CR(*ptr_Cr)>>3) + (NORM_CB_CR(*ptr_Cr)>>5);
			pixel_g = *ptr_Y - ((NORM_CB_CR(*ptr_Cb)>>2) + (NORM_CB_CR(*ptr_Cb)>>4) + (NORM_CB_CR(*ptr_Cb)>>5)) - ((NORM_CB_CR(*ptr_Cr)>>1)+(NORM_CB_CR(*ptr_Cr)>>3)+(NORM_CB_CR(*ptr_Cr)>>4)+(NORM_CB_CR(*ptr_Cr)>>5));
			pixel_b = *ptr_Y + NORM_CB_CR(*ptr_Cb) + (NORM_CB_CR(*ptr_Cb)>>1)+(NORM_CB_CR(*ptr_Cb)>>2)+(NORM_CB_CR(*ptr_Cb)>>6);
			// place r g b in order in 3 bytes
			ptr_rgb[j*rgb_w*rgb_bytes+i] = pixel_r;  ptr_rgb[j*rgb_w*rgb_bytes+i+1] = pixel_g; ptr_rgb[j*rgb_w*rgb_bytes+i+2] = pixel_b;
			printf("i:%d j:%d [Y:%d, Cb:%d, Cr:%d]", i, j, *ptr_Y, *ptr_Cb, *ptr_Cr);
			//printf("i:%d j:%d [Y:%d, Cb:%d, Cr:%d] [R:%d, G:%d, B:%d] ", i, j, *ptr_Y, *ptr_Cb, *ptr_Cr, rgb888_buf[i], rgb888_buf[i+1], rgb888_buf[i+2]);

			ptr_Y +=subsamplingH_Y;
			ptr_Cb+=subsamplingH_UV*2;
			ptr_Cr+=subsamplingH_UV*2;

		}
		printf("\n");

	}

}


void yuv420torgb565(  uint8_t* yuv_buf
					, uint8_t* rgb_buf
					, uint32_t yuv_w
					, uint32_t yuv_h
					, uint32_t rgb_w
					, uint32_t rgb_h
				)
{
	uint32_t subsamplingH_Y = yuv_w/rgb_w;       // detect the subsampling factor horizontal of Y
	uint32_t subsamplingV_Y = yuv_h/rgb_h;       // detect the subsampling factor vertical of Y
	uint32_t subsamplingH_UV = subsamplingH_Y/2; // detect the subsampling factor horizontal of UV : subsampling factor UV is Y/2 because of YCC420
	uint32_t subsamplingV_UV = subsamplingV_Y/2; // detect the subsampling factor vertical of UV
	uint8_t  rgb_bytes  = 2;  //rgb has 16 = 5+6+5 bits

	uint32_t y_w = yuv_w;
	uint32_t y_h = yuv_h;
	uint32_t uv_w = yuv_w / 2; // uv width is half of y width

	uint8_t* ptr_Y  = yuv_buf;
	uint8_t* ptr_Cb = yuv_buf + y_w*y_h; //CbCr buffer is interleaved and is after Y buffer,  UV data pattern: UVUVUVUVUV
	uint8_t* ptr_Cr = ptr_Cb + 1;
	uint8_t  pixel_r, pixel_g, pixel_b;
	uint8_t* ptr_rgb = rgb_buf;

	for(int j=0; j<rgb_h; j++){
		// when a line is subsampled, we should jump to new line to sample, here we skip directly the lines which don't need to scan.
		ptr_Y  = yuv_buf + j* y_w * subsamplingV_Y;
		ptr_Cb = yuv_buf + y_w*y_h + j * uv_w * 2 * subsamplingV_UV;
		ptr_Cr = yuv_buf + y_w*y_h + 1 + j * uv_w * 2 * subsamplingV_UV;
		for (int i=0; i<rgb_w*rgb_bytes; i+=rgb_bytes){
			// convert the yuv data to rgb.
			pixel_r = *ptr_Y + NORM_CB_CR(*ptr_Cr) + (NORM_CB_CR(*ptr_Cr)>>2) + (NORM_CB_CR(*ptr_Cr)>>3) + (NORM_CB_CR(*ptr_Cr)>>5);
			pixel_g = *ptr_Y - ((NORM_CB_CR(*ptr_Cb)>>2) + (NORM_CB_CR(*ptr_Cb)>>4) + (NORM_CB_CR(*ptr_Cb)>>5)) - ((NORM_CB_CR(*ptr_Cr)>>1)+(NORM_CB_CR(*ptr_Cr)>>3)+(NORM_CB_CR(*ptr_Cr)>>4)+(NORM_CB_CR(*ptr_Cr)>>5));
			pixel_b = *ptr_Y + NORM_CB_CR(*ptr_Cb) + (NORM_CB_CR(*ptr_Cb)>>1)+(NORM_CB_CR(*ptr_Cb)>>2)+(NORM_CB_CR(*ptr_Cb)>>6);
			// place r g b in order in 2 bytes
			ptr_rgb[j*rgb_w*rgb_bytes+i] =  (uint8_t)(((pixel_r >> 3 ) << 3) + (pixel_g >> 5));
			ptr_rgb[j*rgb_w*rgb_bytes+i+1] = (uint8_t)(((pixel_g & 0x07) << 5) + pixel_b);
			printf("i:%d j:%d [Y:%d, Cb:%d, Cr:%d]", i, j, *ptr_Y, *ptr_Cb, *ptr_Cr);
			//printf("i:%d j:%d [Y:%d, Cb:%d, Cr:%d] [R:%d, G:%d, B:%d] ", i, j, *ptr_Y, *ptr_Cb, *ptr_Cr, rgb888_buf[i], rgb888_buf[i+1], rgb888_buf[i+2]);

			ptr_Y +=subsamplingH_Y;
			ptr_Cb+=subsamplingH_UV*2;
			ptr_Cr+=subsamplingH_UV*2;

		}
		printf("\n");

	}

}

int main(){
	yuv420torgb888(yuv_test_buf, rgb888_buf, 16, 16, 8, 8 );
	printf("------888--------\n");
	for(int j=0; j<8; j++){
		for(int i=0; i<8*3; i+=3){
			printf("i:%d [R:%d, G:%d, B:%d] ", i, rgb888_buf[j*24+i], rgb888_buf[j*24+i+1], rgb888_buf[j*24+i+2]);
		}
		printf("\n");
	}


	printf("-------565-------\n");
	yuv420torgb565(yuv_test_buf, rgb565_buf, 16, 16, 8, 8 );
	for(int j=0; j<8; j++){
		for(int i=0; i<8*2; i+=2){
			printf("i:%d [byte1:%d, byte2:%d] ", i, rgb565_buf[j*16+i], rgb565_buf[j*16+i+1]);
		}
		printf("\n");
	}


	return 0;
}
