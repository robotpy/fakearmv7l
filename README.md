fake-armv7l
===========

This is a LD_PRELOAD library that hooks the uname function and changes the
machine type to be 'armv7l'. The string is intentionally hardcoded for
simplicity.

This exists to allow one to force pip to use a particular machine type when
creating wheels.

Usage
-----

LD_PRELOAD=/path/to/libfakearmv7l.so [command]

Credit
------

Stolen from https://geekscloud.wordpress.com/2012/09/06/faking-output-of-uname-command/

License
-------

Unknown
