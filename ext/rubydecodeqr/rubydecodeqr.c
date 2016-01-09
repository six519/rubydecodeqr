#include "ruby.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <decodeqr.h>
#include <stdio.h>

VALUE RubyDecodeQR = Qnil;
extern "C" void Init_rubydecodeqr();
VALUE method_decode(VALUE, VALUE);

extern "C" void Init_rubydecodeqr(){
    VALUE RubyDecodeQR = rb_define_module("RubyDecodeQR");
    rb_define_method(RubyDecodeQR, "decode", (VALUE(*)(ANYARGS))method_decode,1);
}

VALUE method_decode(VALUE self, VALUE arg_path) {
    const char *img= StringValueCStr(arg_path);
    const char *retValue;

    try{
        IplImage *src=cvLoadImage(img,1);
        QrDecoderHandle decoder=qr_decoder_open();
        short stat=qr_decoder_decode_image(decoder, src);

        QrCodeHeader header;
        
        if(qr_decoder_get_header(decoder,&header)){
            retValue=new char[header.byte_size+1];
            qr_decoder_get_body(decoder,(unsigned char *)retValue, header.byte_size+1);
        }

        qr_decoder_close(decoder);
        cvReleaseImage(&src);
    }catch(cv::Exception& e){
        retValue="An error occurred while decoding the image";
    }

    return rb_str_new_cstr(retValue);
}

