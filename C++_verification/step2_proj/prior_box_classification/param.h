#pragma once
#pragma once
///////////////////////////////////////
///////////////////////////////////////
//ResNet18-SSD
///////////////////////////////////////
///////////////////////////////////////

#define STRIDE2_KERNEL3_PE_NUMBER_2		  1
//#define STRIDE2_KERNEL3_PE_NUMBER_4     1
//#define STRIDE2_KERNEL3_PE_NUMBER_8     1

//#define STRIDE1_KERNEL3_PE_NUMBER_2     1
#define STRIDE1_KERNEL3_PE_NUMBER_4       1
//#define STRIDE1_KERNEL3_PE_NUMBER_8     1



/***********************************
************************************
*********CONV1_1 parameter********
************************************
***********************************/
#define CONV_1_1_CHANNEL_NUMBER    		3
#define CONV_1_1_HEIGHT				512
#define CONV_1_1_WIDTH 				768
#define CONV_1_1_OUT_CHANNEL_NUMBER  	64
//log2(OUT_CHANNEL_NUMBER)
#define CONV_1_1_BIAS_ADDR_WIDTH		6
#define CONV_1_1_FL_LAYER_IN 			0
#define CONV_1_1_FL_LAYER_OUT 		4
#define CONV_1_1_FL_PARAM  			12

#if	 STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_1_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_1_MEMORY_SIZE			96
//log2(MEMORY_SIZE)
#define CONV_1_1_ADDR_WIDTH               	7

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_1_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_1_MEMORY_SIZE			48
//log2(MEMORY_SIZE)
#define CONV_1_1_ADDR_WIDTH                   	6

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_1_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_1_MEMORY_SIZE			24
//log2(MEMORY_SIZE)
#define CONV_1_1_ADDR_WIDTH                  	5

#endif


/***********************************
************************************
*********CONV1_2 parameter********
************************************
***********************************/
#define CONV_1_2_CHANNEL_NUMBER    		64
#define CONV_1_2_HEIGHT				512
#define CONV_1_2_WIDTH 				768
#define CONV_1_2_OUT_CHANNEL_NUMBER  	64
//log2(OUT_CHANNEL_NUMBER)
#define CONV_1_2_BIAS_ADDR_WIDTH		6
#define CONV_1_2_FL_LAYER_IN 			4
#define CONV_1_2_FL_LAYER_OUT 		4
#define CONV_1_2_FL_PARAM  			8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_1_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_2_MEMORY_SIZE			2048
//log2(MEMORY_SIZE)
#define CONV_1_2_ADDR_WIDTH               	11

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_1_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_2_MEMORY_SIZE			1024
//log2(MEMORY_SIZE)
#define CONV_1_2_ADDR_WIDTH                   	10

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_1_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_2_MEMORY_SIZE			512
//log2(MEMORY_SIZE)
#define CONV_1_2_ADDR_WIDTH                  	9

#endif


/***********************************
************************************
*********CONV1_3 parameter********
************************************
***********************************/
#define CONV_1_3_CHANNEL_NUMBER    		64
#define CONV_1_3_HEIGHT				512
#define CONV_1_3_WIDTH 				768
#define CONV_1_3_OUT_CHANNEL_NUMBER  	64
//log2(OUT_CHANNEL_NUMBER)
#define CONV_1_3_BIAS_ADDR_WIDTH		6
#define CONV_1_3_FL_LAYER_IN 			4
#define CONV_1_3_FL_LAYER_OUT 		5
#define CONV_1_3_FL_PARAM  			8

#if	STRIDE2_KERNEL3_PE_NUMBER_2

#define CONV_1_3_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_3_MEMORY_SIZE			2048
//log2(MEMORY_SIZE)
#define CONV_1_3_ADDR_WIDTH               	11

#elif	STRIDE2_KERNEL3_PE_NUMBER_4

#define CONV_1_3_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_3_MEMORY_SIZE			1024
//log2(MEMORY_SIZE)
#define CONV_1_3_ADDR_WIDTH                   	10

#elif	STRIDE2_KERNEL3_PE_NUMBER_8

#define CONV_1_3_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_1_3_MEMORY_SIZE			512
//log2(MEMORY_SIZE)
#define CONV_1_3_ADDR_WIDTH                  	9

#endif


/***********************************
************************************
*********CONV2_1_1 parameter********
************************************
***********************************/
#define CONV_2_1_1_CHANNEL_NUMBER    		64
#define CONV_2_1_1_HEIGHT					128
#define CONV_2_1_1_WIDTH 					192
#define CONV_2_1_1_OUT_CHANNEL_NUMBER  	64
//log2(OUT_CHANNEL_NUMBER)
#define CONV_2_1_1_BIAS_ADDR_WIDTH		6
#define CONV_2_1_1_FL_LAYER_IN 			5
#define CONV_2_1_1_FL_LAYER_OUT 			4
#define CONV_2_1_1_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_2_1_1_PE_NUMBER 				2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_1_1_MEMORY_SIZE			2048
//log2(MEMORY_SIZE)
#define CONV_2_1_1_ADDR_WIDTH               		11

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_2_1_1_PE_NUMBER 				4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_1_1_MEMORY_SIZE			1024
//log2(MEMORY_SIZE)
#define CONV_2_1_1_ADDR_WIDTH                   	10

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_2_1_1_PE_NUMBER 				8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_1_1_MEMORY_SIZE			512
//log2(MEMORY_SIZE)
#define CONV_2_1_1_ADDR_WIDTH                  		9

#endif

/***********************************
************************************
*********CONV2_1_2 parameter********
************************************
***********************************/
#define CONV_2_1_2_CHANNEL_NUMBER    		64
#define CONV_2_1_2_HEIGHT					128
#define CONV_2_1_2_WIDTH 					192
#define CONV_2_1_2_OUT_CHANNEL_NUMBER  	64
//log2(OUT_CHANNEL_NUMBER)
#define CONV_2_1_2_BIAS_ADDR_WIDTH		6
#define CONV_2_1_2_FL_LAYER_IN 			4
#define CONV_2_1_2_FL_LAYER_OUT 			4
#define CONV_2_1_2_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_2_1_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_1_2_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_2_1_2_ADDR_WIDTH               	11

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_2_1_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_1_2_MEMORY_SIZE		1024
//log2(MEMORY_SIZE)
#define CONV_2_1_2_ADDR_WIDTH                   10

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_2_1_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_1_2_MEMORY_SIZE		512
//log2(MEMORY_SIZE)
#define CONV_2_1_2_ADDR_WIDTH                  9

#endif

/***********************************
************************************
*********CONV2_2_1 parameter********
************************************
***********************************/
#define CONV_2_2_1_CHANNEL_NUMBER    		64
#define CONV_2_2_1_HEIGHT					128
#define CONV_2_2_1_WIDTH 					192
#define CONV_2_2_1_OUT_CHANNEL_NUMBER  	64
//log2(OUT_CHANNEL_NUMBER)
#define CONV_2_2_1_BIAS_ADDR_WIDTH		6
#define CONV_2_2_1_FL_LAYER_IN 			4
#define CONV_2_2_1_FL_LAYER_OUT 			4
#define CONV_2_2_1_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_2_2_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_2_1_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_2_2_1_ADDR_WIDTH               	11

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_2_2_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_2_1_MEMORY_SIZE		1024
//log2(MEMORY_SIZE)
#define CONV_2_2_1_ADDR_WIDTH                   10

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_2_2_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_2_1_MEMORY_SIZE		512
//log2(MEMORY_SIZE)
#define CONV_2_2_1_ADDR_WIDTH                  9

#endif

/***********************************
************************************
*********CONV2_2_2 parameter********
************************************
***********************************/
#define CONV_2_2_2_CHANNEL_NUMBER    		64
#define CONV_2_2_2_HEIGHT					128
#define CONV_2_2_2_WIDTH 					192
#define CONV_2_2_2_OUT_CHANNEL_NUMBER  	64
//log2(OUT_CHANNEL_NUMBER)
#define CONV_2_2_2_BIAS_ADDR_WIDTH		6
#define CONV_2_2_2_FL_LAYER_IN 			4
#define CONV_2_2_2_FL_LAYER_OUT 			4
#define CONV_2_2_2_FL_PARAM  				7

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_2_2_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_2_2_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_2_2_2_ADDR_WIDTH               	11

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_2_2_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_2_2_MEMORY_SIZE		1024
//log2(MEMORY_SIZE)
#define CONV_2_2_2_ADDR_WIDTH                   10

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_2_2_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_2_2_2_MEMORY_SIZE		512
//log2(MEMORY_SIZE)
#define CONV_2_2_2_ADDR_WIDTH                  9

#endif

/***********************************
************************************
*********CONV2_proj parameter********
************************************
***********************************/
#define CONV2_PROJ_CHANNEL_NUMBER  64
#define CONV2_PROJ_HEIGHT 		128
#define CONV2_PROJ_WIDTH 		192
#define CONV2_PROJ_OUT_CHANNEL_NUMBER  	128
#define CONV2_PROJ_PE_NUMBER  			16
//log2(CONV2_proj_OUT_CHANNEL_NUMBER)
#define CONV2_PROJ_BIAS_ADDR_WIDTH		7
#define CONV2_PROJ_FL_LAYER_IN 			3
#define CONV2_PROJ_FL_LAYER_OUT 			6
#define CONV2_PROJ_FL_PARAM  				9

//log2(CONV2_proj_CHANNEL_NUMBER)
#define CONV2_PROJ_CHANNEL_NUMBER_WIDTH     6

#if	STRIDE1_KERNEL3_PE_NUMBER_2
#define CONV2_PROJ_PRE_PE_NUMBER  2
#elif	STRIDE1_KERNEL3_PE_NUMBER_4
#define CONV2_PROJ_PRE_PE_NUMBER  4
#elif	STRIDE1_KERNEL3_PE_NUMBER_8
#define CONV2_PROJ_PRE_PE_NUMBER  8
#endif




/***********************************
************************************
*********CONV3_1_1 parameter********
************************************
***********************************/
#define CONV_3_1_1_CHANNEL_NUMBER    		64
#define CONV_3_1_1_HEIGHT					128
#define CONV_3_1_1_WIDTH 					192
#define CONV_3_1_1_OUT_CHANNEL_NUMBER  	128
//log2(OUT_CHANNEL_NUMBER)
#define CONV_3_1_1_BIAS_ADDR_WIDTH		7
#define CONV_3_1_1_FL_LAYER_IN 			3
#define CONV_3_1_1_FL_LAYER_OUT 			5
#define CONV_3_1_1_FL_PARAM  				10

#if	STRIDE2_KERNEL3_PE_NUMBER_2

#define CONV_3_1_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_1_1_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_3_1_1_ADDR_WIDTH               	12

#elif	STRIDE2_KERNEL3_PE_NUMBER_4

#define CONV_3_1_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_1_1_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_3_1_1_ADDR_WIDTH                   11

#elif	STRIDE2_KERNEL3_PE_NUMBER_8

#define CONV_3_1_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_1_1_MEMORY_SIZE		1024
//log2(MEMORY_SIZE)
#define CONV_3_1_1_ADDR_WIDTH                  10

#endif


/***********************************
************************************
*********CONV3_1_2 parameter********
************************************
***********************************/
#define CONV_3_1_2_CHANNEL_NUMBER    		128
#define CONV_3_1_2_HEIGHT					64
#define CONV_3_1_2_WIDTH 					96
#define CONV_3_1_2_OUT_CHANNEL_NUMBER  	128
//log2(OUT_CHANNEL_NUMBER)
#define CONV_3_1_2_BIAS_ADDR_WIDTH		7
#define CONV_3_1_2_FL_LAYER_IN 			5
#define CONV_3_1_2_FL_LAYER_OUT 			4
#define CONV_3_1_2_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_3_1_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_1_2_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_3_1_2_ADDR_WIDTH               	13

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_3_1_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_1_2_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_3_1_2_ADDR_WIDTH                   12

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_3_1_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_1_2_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_3_1_2_ADDR_WIDTH                  11

#endif


/***********************************
************************************
*********CONV3_2_1 parameter********
************************************
***********************************/
#define CONV_3_2_1_CHANNEL_NUMBER    		128
#define CONV_3_2_1_HEIGHT					64
#define CONV_3_2_1_WIDTH 					96
#define CONV_3_2_1_OUT_CHANNEL_NUMBER  	128
//log2(OUT_CHANNEL_NUMBER)
#define CONV_3_2_1_BIAS_ADDR_WIDTH		7
#define CONV_3_2_1_FL_LAYER_IN 			4
#define CONV_3_2_1_FL_LAYER_OUT 			4
#define CONV_3_2_1_FL_PARAM  				7

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_3_2_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_1_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_3_2_1_ADDR_WIDTH               	13

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_3_2_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_1_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_3_2_1_ADDR_WIDTH                   12

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_3_2_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_1_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_3_2_1_ADDR_WIDTH                  11

#endif


/***********************************
************************************
*********CONV3_2_2 parameter********
************************************
***********************************/
#define CONV_3_2_2_CHANNEL_NUMBER    		128
#define CONV_3_2_2_HEIGHT					64
#define CONV_3_2_2_WIDTH 					96
#define CONV_3_2_2_OUT_CHANNEL_NUMBER  	128
//log2(OUT_CHANNEL_NUMBER)
#define CONV_3_2_2_BIAS_ADDR_WIDTH		7
#define CONV_3_2_2_FL_LAYER_IN 			4
#define CONV_3_2_2_FL_LAYER_OUT 			3
#define CONV_3_2_2_FL_PARAM  				7

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_3_2_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_2_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_3_2_2_ADDR_WIDTH               	13

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_3_2_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_2_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_3_2_2_ADDR_WIDTH                   12

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_3_2_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_2_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_3_2_2_ADDR_WIDTH                  11

#endif

/***********************************
************************************
*********CONV3_proj parameter********
************************************
***********************************/
#define CONV3_PROJ_CHANNEL_NUMBER  128
#define CONV3_PROJ_HEIGHT 		64
#define CONV3_PROJ_WIDTH 		96
#define CONV3_PROJ_OUT_CHANNEL_NUMBER  	256
#define CONV3_PROJ_PE_NUMBER  			16
//log2(CONV3_proj_OUT_CHANNEL_NUMBER)
#define CONV3_PROJ_BIAS_ADDR_WIDTH		8
#define CONV3_PROJ_FL_LAYER_IN 			3
#define CONV3_PROJ_FL_LAYER_OUT 			6
#define CONV3_PROJ_FL_PARAM  				9

//log2(CONV3_proj_CHANNEL_NUMBER)
#define CONV3_PROJ_CHANNEL_NUMBER_WIDTH     7

#if	STRIDE1_KERNEL3_PE_NUMBER_2
#define CONV3_PROJ_PRE_PE_NUMBER  2
#elif	STRIDE1_KERNEL3_PE_NUMBER_4
#define CONV3_PROJ_PRE_PE_NUMBER  4
#elif	STRIDE1_KERNEL3_PE_NUMBER_8
#define CONV3_PROJ_PRE_PE_NUMBER  8
#endif




/***********************************
************************************
*********CONV4_1_1 parameter********
************************************
***********************************/
#define CONV_4_1_1_CHANNEL_NUMBER    		128
#define CONV_4_1_1_HEIGHT					64
#define CONV_4_1_1_WIDTH 					96
#define CONV_4_1_1_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_4_1_1_BIAS_ADDR_WIDTH		8
#define CONV_4_1_1_FL_LAYER_IN 			3
#define CONV_4_1_1_FL_LAYER_OUT 			5
#define CONV_4_1_1_FL_PARAM  				9

#if	STRIDE2_KERNEL3_PE_NUMBER_2

#define CONV_4_1_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_1_1_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_4_1_1_ADDR_WIDTH               	14

#elif	STRIDE2_KERNEL3_PE_NUMBER_4

#define CONV_4_1_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_1_1_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_4_1_1_ADDR_WIDTH                  13

#elif	STRIDE2_KERNEL3_PE_NUMBER_8

#define CONV_4_1_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_1_1_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_4_1_1_ADDR_WIDTH                  12

#endif


/***********************************
************************************
*********CONV4_1_2 parameter********
************************************
***********************************/
#define CONV_4_1_2_CHANNEL_NUMBER    		256
#define CONV_4_1_2_HEIGHT					32
#define CONV_4_1_2_WIDTH 					48
#define CONV_4_1_2_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_4_1_2_BIAS_ADDR_WIDTH		8
#define CONV_4_1_2_FL_LAYER_IN 			5
#define CONV_4_1_2_FL_LAYER_OUT 			5
#define CONV_4_1_2_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_4_1_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_1_2_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_4_1_2_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_4_1_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_1_2_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_4_1_2_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_4_1_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_1_2_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_4_1_2_ADDR_WIDTH                  13

#endif

/***********************************
************************************
*********CONV4_2_1 parameter********
************************************
***********************************/
#define CONV_4_2_1_CHANNEL_NUMBER    		256
#define CONV_4_2_1_HEIGHT					32
#define CONV_4_2_1_WIDTH 					48
#define CONV_4_2_1_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_4_2_1_BIAS_ADDR_WIDTH		8
#define CONV_4_2_1_FL_LAYER_IN 			5
#define CONV_4_2_1_FL_LAYER_OUT 			5
#define CONV_4_2_1_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_4_2_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_1_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_4_2_1_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_4_2_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_1_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_4_2_1_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_4_2_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_1_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_4_2_1_ADDR_WIDTH                  13

#endif

/***********************************
************************************
*********CONV4_2_2 parameter********
************************************
***********************************/
#define CONV_4_2_2_CHANNEL_NUMBER    		256
#define CONV_4_2_2_HEIGHT					32
#define CONV_4_2_2_WIDTH 					48
#define CONV_4_2_2_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_4_2_2_BIAS_ADDR_WIDTH		8
#define CONV_4_2_2_FL_LAYER_IN 			5
#define CONV_4_2_2_FL_LAYER_OUT 			3
#define CONV_4_2_2_FL_PARAM  				6

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_4_2_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_2_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_4_2_2_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_4_2_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_2_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_4_2_2_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_4_2_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_2_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_4_2_2_ADDR_WIDTH                  13

#endif

// 五层
/***********************************
************************************
*********CONV4_proj parameter********
************************************
***********************************/
#define CONV4_PROJ_CHANNEL_NUMBER  256
#define CONV4_PROJ_HEIGHT 		32
#define CONV4_PROJ_WIDTH 		48
#define CONV4_PROJ_OUT_CHANNEL_NUMBER  	512
#define CONV4_PROJ_PE_NUMBER  			16
//log2(CONV4_proj_OUT_CHANNEL_NUMBER)
#define CONV4_PROJ_BIAS_ADDR_WIDTH		9
#define CONV4_PROJ_FL_LAYER_IN 			4
#define CONV4_PROJ_FL_LAYER_OUT 			6
#define CONV4_PROJ_FL_PARAM  				9

//log2(CONV4_proj_CHANNEL_NUMBER)
#define CONV4_PROJ_CHANNEL_NUMBER_WIDTH     8

#if	STRIDE1_KERNEL3_PE_NUMBER_2
#define CONV4_PROJ_PRE_PE_NUMBER  2
#elif	STRIDE1_KERNEL3_PE_NUMBER_4
#define CONV4_PROJ_PRE_PE_NUMBER  4
#elif	STRIDE1_KERNEL3_PE_NUMBER_8
#define CONV4_PROJ_PRE_PE_NUMBER  8
#endif




/***********************************
************************************
*********CONV5_1_1 parameter********
************************************
***********************************/
#define CONV_5_1_1_CHANNEL_NUMBER    		256
#define CONV_5_1_1_HEIGHT					32
#define CONV_5_1_1_WIDTH 					48
#define CONV_5_1_1_OUT_CHANNEL_NUMBER  	512
//log2(OUT_CHANNEL_NUMBER)
#define CONV_5_1_1_BIAS_ADDR_WIDTH		9
#define CONV_5_1_1_FL_LAYER_IN 			4
#define CONV_5_1_1_FL_LAYER_OUT 			6
#define CONV_5_1_1_FL_PARAM  				10

#if	STRIDE2_KERNEL3_PE_NUMBER_2

#define CONV_5_1_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_1_1_MEMORY_SIZE		65536
//log2(MEMORY_SIZE)
#define CONV_5_1_1_ADDR_WIDTH               	16

#elif	STRIDE2_KERNEL3_PE_NUMBER_4

#define CONV_5_1_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_1_1_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_5_1_1_ADDR_WIDTH                  15

#elif	STRIDE2_KERNEL3_PE_NUMBER_8

#define CONV_5_1_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_1_1_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_5_1_1_ADDR_WIDTH                  14

#endif


/***********************************
************************************
*********CONV5_1_2 parameter********
************************************
***********************************/
#define CONV_5_1_2_CHANNEL_NUMBER    		512
#define CONV_5_1_2_HEIGHT					16
#define CONV_5_1_2_WIDTH 					24
#define CONV_5_1_2_OUT_CHANNEL_NUMBER  	512
//log2(OUT_CHANNEL_NUMBER)
#define CONV_5_1_2_BIAS_ADDR_WIDTH		9
#define CONV_5_1_2_FL_LAYER_IN 			6
#define CONV_5_1_2_FL_LAYER_OUT 			5
#define CONV_5_1_2_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_5_1_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_1_2_MEMORY_SIZE		131072
//log2(MEMORY_SIZE)
#define CONV_5_1_2_ADDR_WIDTH               	17

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_5_1_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_1_2_MEMORY_SIZE		65536
//log2(MEMORY_SIZE)
#define CONV_5_1_2_ADDR_WIDTH                   16

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_5_1_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_1_2_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_5_1_2_ADDR_WIDTH                  15

#endif

/***********************************
************************************
*********CONV5_2_1 parameter********
************************************
***********************************/
#define CONV_5_2_1_CHANNEL_NUMBER    		512
#define CONV_5_2_1_HEIGHT					16
#define CONV_5_2_1_WIDTH 					24
#define CONV_5_2_1_OUT_CHANNEL_NUMBER  	512
//log2(OUT_CHANNEL_NUMBER)
#define CONV_5_2_1_BIAS_ADDR_WIDTH		9
#define CONV_5_2_1_FL_LAYER_IN 			5
#define CONV_5_2_1_FL_LAYER_OUT 			6
#define CONV_5_2_1_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_5_2_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_1_MEMORY_SIZE		131072
//log2(MEMORY_SIZE)
#define CONV_5_2_1_ADDR_WIDTH               	17

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_5_2_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_1_MEMORY_SIZE		65536
//log2(MEMORY_SIZE)
#define CONV_5_2_1_ADDR_WIDTH                   16

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_5_2_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_1_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_5_2_1_ADDR_WIDTH                  15

#endif

/***********************************
************************************
*********CONV5_2_2 parameter********
************************************
***********************************/
#define CONV_5_2_2_CHANNEL_NUMBER    		512
#define CONV_5_2_2_HEIGHT					16
#define CONV_5_2_2_WIDTH 					24
#define CONV_5_2_2_OUT_CHANNEL_NUMBER  	512
//log2(OUT_CHANNEL_NUMBER)
#define CONV_5_2_2_BIAS_ADDR_WIDTH		9
#define CONV_5_2_2_FL_LAYER_IN 			6
#define CONV_5_2_2_FL_LAYER_OUT 			4
#define CONV_5_2_2_FL_PARAM  				7

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_5_2_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_2_MEMORY_SIZE		131072
//log2(MEMORY_SIZE)
#define CONV_5_2_2_ADDR_WIDTH               	17

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_5_2_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_2_MEMORY_SIZE		65536
//log2(MEMORY_SIZE)
#define CONV_5_2_2_ADDR_WIDTH                   16

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_5_2_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_2_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_5_2_2_ADDR_WIDTH                  15

#endif


///////////////////////
////第六层/////////////
///////////////////////

// 6层
/***********************************
************************************
*********CONV6_proj parameter********
************************************
***********************************/
#define CONV6_PROJ_CHANNEL_NUMBER  512
#define CONV6_PROJ_HEIGHT 		16
#define CONV6_PROJ_WIDTH 		24
#define CONV6_PROJ_OUT_CHANNEL_NUMBER  	256
#define CONV6_PROJ_PE_NUMBER  			16
//log2(CONV6_proj_OUT_CHANNEL_NUMBER)
#define CONV6_PROJ_BIAS_ADDR_WIDTH		8
#define CONV6_PROJ_FL_LAYER_IN 			4
#define CONV6_PROJ_FL_LAYER_OUT 			4
#define CONV6_PROJ_FL_PARAM  				8

//log2(CONV6_proj_CHANNEL_NUMBER)
#define CONV6_PROJ_CHANNEL_NUMBER_WIDTH     9

#if	STRIDE1_KERNEL3_PE_NUMBER_2
#define CONV6_PROJ_PRE_PE_NUMBER  2
#elif	STRIDE1_KERNEL3_PE_NUMBER_4
#define CONV6_PROJ_PRE_PE_NUMBER  4
#elif	STRIDE1_KERNEL3_PE_NUMBER_8
#define CONV6_PROJ_PRE_PE_NUMBER  8
#endif



/***********************************
************************************
*********CONV6_1 parameter********
************************************
***********************************/
#define CONV_6_1_CHANNEL_NUMBER    		512
#define CONV_6_1_HEIGHT					16
#define CONV_6_1_WIDTH 					24
#define CONV_6_1_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_6_1_BIAS_ADDR_WIDTH		8
#define CONV_6_1_FL_LAYER_IN 			4
#define CONV_6_1_FL_LAYER_OUT 			5
#define CONV_6_1_FL_PARAM  				10

#if	STRIDE2_KERNEL3_PE_NUMBER_2

#define CONV_6_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_1_MEMORY_SIZE		65536
//log2(MEMORY_SIZE)
#define CONV_6_1_ADDR_WIDTH               	16

#elif	STRIDE2_KERNEL3_PE_NUMBER_4

#define CONV_6_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_1_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_6_1_ADDR_WIDTH                   15

#elif	STRIDE2_KERNEL3_PE_NUMBER_8

#define CONV_6_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_1_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_6_1_ADDR_WIDTH                  14

#endif

/***********************************
************************************
*********CONV6_2 parameter********
************************************
***********************************/
#define CONV_6_2_CHANNEL_NUMBER    		256
#define CONV_6_2_HEIGHT					8
#define CONV_6_2_WIDTH 					12
#define CONV_6_2_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_6_2_BIAS_ADDR_WIDTH		8
#define CONV_6_2_FL_LAYER_IN 			5
#define CONV_6_2_FL_LAYER_OUT 			3
#define CONV_6_2_FL_PARAM  				6

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_6_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_2_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_6_2_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_6_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_2_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_6_2_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_6_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_2_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_6_2_ADDR_WIDTH                  13

#endif




///////////////////////
////第七层/////////////
///////////////////////

/***********************************
************************************
*********CONV7_1 parameter********
************************************
***********************************/
#define CONV_7_1_CHANNEL_NUMBER    		256
#define CONV_7_1_HEIGHT					8
#define CONV_7_1_WIDTH 					12
#define CONV_7_1_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_7_1_BIAS_ADDR_WIDTH		8
#define CONV_7_1_FL_LAYER_IN 			2
#define CONV_7_1_FL_LAYER_OUT 			6
#define CONV_7_1_FL_PARAM  				11

#if	STRIDE2_KERNEL3_PE_NUMBER_2

#define CONV_7_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_1_MEMORY_SIZE		32768
//log2(MEMOR7_SIZE)
#define CONV_7_1_ADDR_WIDTH               	15

#elif	STRIDE2_KERNEL3_PE_NUMBER_4

#define CONV_7_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_1_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_7_1_ADDR_WIDTH                   14

#elif	STRIDE2_KERNEL3_PE_NUMBER_8

#define CONV_7_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_1_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_7_1_ADDR_WIDTH                  13

#endif


/***********************************
************************************
*********CONV7_2 parameter********
************************************
***********************************/
#define CONV_7_2_CHANNEL_NUMBER    		256
#define CONV_7_2_HEIGHT					4
#define CONV_7_2_WIDTH 					6
#define CONV_7_2_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_7_2_BIAS_ADDR_WIDTH		8
#define CONV_7_2_FL_LAYER_IN 			6
#define CONV_7_2_FL_LAYER_OUT 			4
#define CONV_7_2_FL_PARAM  				5

#if	STRIDE1_KERNEL3_PE_NUMBER_2


#define CONV_7_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_2_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_7_2_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_7_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_2_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_7_2_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_7_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_2_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_7_2_ADDR_WIDTH                  13

#endif

///////////////////////
////第八层/////////////
///////////////////////

/***********************************
************************************
*********CONV8_1 parameter********
************************************
***********************************/
#define CONV_8_1_CHANNEL_NUMBER    		256
#define CONV_8_1_HEIGHT					4
#define CONV_8_1_WIDTH 					6
#define CONV_8_1_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_8_1_BIAS_ADDR_WIDTH		8
#define CONV_8_1_FL_LAYER_IN 			2
#define CONV_8_1_FL_LAYER_OUT 			6
#define CONV_8_1_FL_PARAM  				12

#if	STRIDE2_KERNEL3_PE_NUMBER_2

#define CONV_8_1_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_1_MEMORY_SIZE		32768
//log2(MEMOR7_SIZE)
#define CONV_8_1_ADDR_WIDTH               	15

#elif	STRIDE2_KERNEL3_PE_NUMBER_4

#define CONV_8_1_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_1_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_8_1_ADDR_WIDTH                   14

#elif	STRIDE2_KERNEL3_PE_NUMBER_8

#define CONV_8_1_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_1_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_8_1_ADDR_WIDTH                  13

#endif

/***********************************
************************************
*********CONV8_2 parameter********
************************************
***********************************/
#define CONV_8_2_CHANNEL_NUMBER    		256
#define CONV_8_2_HEIGHT					2
#define CONV_8_2_WIDTH 					3
#define CONV_8_2_OUT_CHANNEL_NUMBER  	256
//log2(OUT_CHANNEL_NUMBER)
#define CONV_8_2_BIAS_ADDR_WIDTH		8
#define CONV_8_2_FL_LAYER_IN 			6
#define CONV_8_2_FL_LAYER_OUT 			5
#define CONV_8_2_FL_PARAM  				7

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_8_2_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_2_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_8_2_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_8_2_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_2_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_8_2_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_8_2_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_2_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_8_2_ADDR_WIDTH                  13

#endif



/////////////////////////////////////conf层///////////////////////

/***********************************
************************************
*********CONV3_2_conf********
************************************
***********************************/
#define CONV_3_2_CONF_CHANNEL_NUMBER    		128
#define CONV_3_2_CONF_HEIGHT					64
#define CONV_3_2_CONF_WIDTH 					96
#define CONV_3_2_CONF_OUT_CHANNEL_NUMBER  	80   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_3_2_CONF_BIAS_ADDR_WIDTH		7
#define CONV_3_2_CONF_LAYER_IN 			3
#define CONV_3_2_CONF_FL_LAYER_OUT 			3
#define CONV_3_2_CONF_FL_PARAM  				7

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_3_2_CONF_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_CONF_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_3_2_CONF_ADDR_WIDTH               	13

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_3_2_CONF_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_CONF_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_3_2_CONF_ADDR_WIDTH                   12

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_3_2_CONF_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_CONF_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_3_2_CONF_ADDR_WIDTH                  11

#endif




/***********************************
************************************
*********CONV4_2_conf********
************************************
***********************************/
#define CONV_4_2_CONF_CHANNEL_NUMBER    		256
#define CONV_4_2_CONF_HEIGHT					32
#define CONV_4_2_CONF_WIDTH 					48
#define CONV_4_2_CONF_OUT_CHANNEL_NUMBER  	80   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_4_2_CONF_BIAS_ADDR_WIDTH		7
#define CONV_4_2_CONF_LAYER_IN 			4
#define CONV_4_2_CONF_FL_LAYER_OUT 			3
#define CONV_4_2_CONF_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_4_2_CONF_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_CONF_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_4_2_CONF_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_4_2_CONF_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_CONF_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_4_2_CONF_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_4_2_CONF_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_CONF_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_4_2_CONF_ADDR_WIDTH                  12

#endif


/***********************************
************************************
*********CONV5_2_conf********
************************************
***********************************/
#define CONV_5_2_CONF_CHANNEL_NUMBER    		512
#define CONV_5_2_CONF_HEIGHT					16
#define CONV_5_2_CONF_WIDTH 					24
#define CONV_5_2_CONF_OUT_CHANNEL_NUMBER  	80   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_5_2_CONF_BIAS_ADDR_WIDTH		7
#define CONV_5_2_CONF_LAYER_IN 			4
#define CONV_5_2_CONF_FL_LAYER_OUT 			3
#define CONV_5_2_CONF_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_5_2_CONF_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_CONF_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_5_2_CONF_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_5_2_CONF_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_CONF_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_5_2_CONF_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_5_2_CONF_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_CONF_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_5_2_CONF_ADDR_WIDTH                  13

#endif


/***********************************
************************************
*********CONV6_conf********
************************************
***********************************/
#define CONV_6_CONF_CHANNEL_NUMBER    		256
#define CONV_6_CONF_HEIGHT					8
#define CONV_6_CONF_WIDTH 					12
#define CONV_6_CONF_OUT_CHANNEL_NUMBER  	80   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_6_CONF_BIAS_ADDR_WIDTH		7
#define CONV_6_CONF_LAYER_IN 			2
#define CONV_6_CONF_FL_LAYER_OUT 			3
#define CONV_6_CONF_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_6_CONF_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_CONF_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_6_CONF_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_6_CONF_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_CONF_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_6_CONF_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_6_CONF_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_CONF_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_6_CONF_ADDR_WIDTH                  12

#endif

/***********************************
************************************
*********CONV7_conf********
************************************
***********************************/
#define CONV_7_CONF_CHANNEL_NUMBER    		256
#define CONV_7_CONF_HEIGHT					4
#define CONV_7_CONF_WIDTH 					6
#define CONV_7_CONF_OUT_CHANNEL_NUMBER  	80   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_7_CONF_BIAS_ADDR_WIDTH		7
#define CONV_7_CONF_LAYER_IN 			2
#define CONV_7_CONF_FL_LAYER_OUT 			3
#define CONV_7_CONF_FL_PARAM  				9

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_7_CONF_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_CONF_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_7_CONF_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_7_CONF_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_CONF_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_7_CONF_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_7_CONF_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_CONF_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_7_CONF_ADDR_WIDTH                  12

#endif

/***********************************
************************************
*********CONV8_conf********
************************************
***********************************/
#define CONV_8_CONF_CHANNEL_NUMBER    		256
#define CONV_8_CONF_HEIGHT					2
#define CONV_8_CONF_WIDTH 					3
#define CONV_8_CONF_OUT_CHANNEL_NUMBER  	80   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_8_CONF_BIAS_ADDR_WIDTH		7
#define CONV_8_CONF_LAYER_IN 			2
#define CONV_8_CONF_FL_LAYER_OUT 			3
#define CONV_8_CONF_FL_PARAM  				9

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_8_CONF_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_CONF_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_8_CONF_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_8_CONF_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_CONF_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_8_CONF_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_8_CONF_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_CONF_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_8_CONF_ADDR_WIDTH                  12

#endif






/////////////////////////////////////loc层///////////////////////

/***********************************
************************************
*********CONV3_2_LOC********
************************************
***********************************/
#define CONV_3_2_LOC_CHANNEL_NUMBER    		128
#define CONV_3_2_LOC_HEIGHT					64
#define CONV_3_2_LOC_WIDTH 					96
#define CONV_3_2_LOC_OUT_CHANNEL_NUMBER  	40   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_3_2_LOC_BIAS_ADDR_WIDTH		7
#define CONV_3_2_LOC_LAYER_IN 			3
#define CONV_3_2_LOC_FL_LAYER_OUT 			4
#define CONV_3_2_LOC_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_3_2_LOC_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_LOC_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_3_2_LOC_ADDR_WIDTH               	13

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_3_2_LOC_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_LOC_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_3_2_LOC_ADDR_WIDTH                   12

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_3_2_LOC_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_3_2_LOC_MEMORY_SIZE		2048
//log2(MEMORY_SIZE)
#define CONV_3_2_LOC_ADDR_WIDTH                  11

#endif




/***********************************
************************************
*********CONV4_2_LOC********
************************************
***********************************/
#define CONV_4_2_LOC_CHANNEL_NUMBER    		256
#define CONV_4_2_LOC_HEIGHT					32
#define CONV_4_2_LOC_WIDTH 					48
#define CONV_4_2_LOC_OUT_CHANNEL_NUMBER  	40   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_4_2_LOC_BIAS_ADDR_WIDTH		7
#define CONV_4_2_LOC_LAYER_IN 			4
#define CONV_4_2_LOC_FL_LAYER_OUT 			4
#define CONV_4_2_LOC_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_4_2_LOC_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_LOC_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_4_2_LOC_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_4_2_LOC_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_LOC_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_4_2_LOC_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_4_2_LOC_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_4_2_LOC_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_4_2_LOC_ADDR_WIDTH                  12

#endif


/***********************************
************************************
*********CONV5_2_LOC********
************************************
***********************************/
#define CONV_5_2_LOC_CHANNEL_NUMBER    		512
#define CONV_5_2_LOC_HEIGHT					16
#define CONV_5_2_LOC_WIDTH 					24
#define CONV_5_2_LOC_OUT_CHANNEL_NUMBER  	40   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_5_2_LOC_BIAS_ADDR_WIDTH		7
#define CONV_5_2_LOC_LAYER_IN 			4
#define CONV_5_2_LOC_FL_LAYER_OUT 			4
#define CONV_5_2_LOC_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_5_2_LOC_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_LOC_MEMORY_SIZE		32768
//log2(MEMORY_SIZE)
#define CONV_5_2_LOC_ADDR_WIDTH               	15

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_5_2_LOC_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_LOC_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_5_2_LOC_ADDR_WIDTH                   14

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_5_2_LOC_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_5_2_LOC_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_5_2_LOC_ADDR_WIDTH                  13

#endif


/***********************************
************************************
*********CONV6_LOC********
************************************
***********************************/
#define CONV_6_LOC_CHANNEL_NUMBER    		256
#define CONV_6_LOC_HEIGHT					8
#define CONV_6_LOC_WIDTH 					12
#define CONV_6_LOC_OUT_CHANNEL_NUMBER  	40   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_6_LOC_BIAS_ADDR_WIDTH		7
#define CONV_6_LOC_LAYER_IN 			2
#define CONV_6_LOC_FL_LAYER_OUT 			4
#define CONV_6_LOC_FL_PARAM  				8

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_6_LOC_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_LOC_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_6_LOC_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_6_LOC_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_LOC_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_6_LOC_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_6_LOC_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_6_LOC_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_6_LOC_ADDR_WIDTH                  12

#endif

/***********************************
************************************
*********CONV7_LOC********
************************************
***********************************/
#define CONV_7_LOC_CHANNEL_NUMBER    		256
#define CONV_7_LOC_HEIGHT					4
#define CONV_7_LOC_WIDTH 					6
#define CONV_7_LOC_OUT_CHANNEL_NUMBER  	40   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_7_LOC_BIAS_ADDR_WIDTH		7
#define CONV_7_LOC_LAYER_IN 			2
#define CONV_7_LOC_FL_LAYER_OUT 			4
#define CONV_7_LOC_FL_PARAM  				9

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_7_LOC_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_LOC_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_7_LOC_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_7_LOC_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_LOC_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_7_LOC_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_7_LOC_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_7_LOC_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_7_LOC_ADDR_WIDTH                  12

#endif

/***********************************
************************************
*********CONV8_LOC********
************************************
***********************************/
#define CONV_8_LOC_CHANNEL_NUMBER    		256
#define CONV_8_LOC_HEIGHT					2
#define CONV_8_LOC_WIDTH 					3
#define CONV_8_LOC_OUT_CHANNEL_NUMBER  	40   //当成128的来计算
//log2(OUT_CHANNEL_NUMBER)
#define CONV_8_LOC_BIAS_ADDR_WIDTH		7
#define CONV_8_LOC_LAYER_IN 			2
#define CONV_8_LOC_FL_LAYER_OUT 			4
#define CONV_8_LOC_FL_PARAM  				9

#if	STRIDE1_KERNEL3_PE_NUMBER_2

#define CONV_8_LOC_PE_NUMBER 			2
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_LOC_MEMORY_SIZE		16384
//log2(MEMORY_SIZE)
#define CONV_8_LOC_ADDR_WIDTH               	14

#elif	STRIDE1_KERNEL3_PE_NUMBER_4

#define CONV_8_LOC_PE_NUMBER 			4
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_LOC_MEMORY_SIZE		8192
//log2(MEMORY_SIZE)
#define CONV_8_LOC_ADDR_WIDTH                   13

#elif	STRIDE1_KERNEL3_PE_NUMBER_8

#define CONV_8_LOC_PE_NUMBER 			8
//CHANNEL_NUMBER*OUT_CHANNEL_NUMBER/PE_NUMBE		
#define CONV_8_LOC_MEMORY_SIZE		4096
//log2(MEMORY_SIZE)
#define CONV_8_LOC_ADDR_WIDTH                  12

#endif