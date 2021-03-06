
#include "minifyjpeg.h"
#include "magickminify.h"

/* Implement the needed server-side functions here */

/*
rpc_minify_out * rpc_minify_jpeg_proc_1(rpc_minify_in src, CLIENT* cli)
{
    printf("THIS IS THE PROC_1 FUNCTION \n \n");
    return NULL;
}
*/

rpc_minify_out * rpc_minify_jpeg_proc_1_svc(rpc_minify_in in , struct svc_req * req)
{
    printf("THIS IS THE PROC_1_SVC FUNCTION \n \n");
    rpc_minify_out * dest = malloc(sizeof *dest);

    ssize_t src_length = in.src.src_len;
    fprintf(stderr,"file source length = %d\n",in.src.src_len);

    ssize_t dst_length;

    magickminify_init();

    printf("run magick minify\n");

    dest->dest.dest_val = magickminify((void*)in.src.src_val,src_length,&dst_length);

    printf("set return length of %zu\n",dst_length);
    dest->dest.dest_len = dst_length;

    printf("cleanup and return\n");
    magickminify_cleanup();

    return dest;
}