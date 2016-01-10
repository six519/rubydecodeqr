RuybGems Link
=============

https://rubygems.org/gems/rubydecodeqr

rubydecodeqr
============

Decode QR code image file using libdecodeqr (Ruby Extension in C++ Sample Code). Code tested in Ubuntu 15.04

Install Requirements
====================
::

    apt-get install libdecodeqr-dev libopencv-dev

Installing
==========
::

    gem install rubydecodeqr

Ruby Sample Usage
=================
::

    require 'rubydecodeqr/rubydecodeqr'
    include RubyDecodeQR
    data = decode '/home/six519/test.png'
