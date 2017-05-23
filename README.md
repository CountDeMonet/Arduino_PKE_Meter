# Arduino_PKE_Meter
Code and models for an arduino based Ghostbusters PKE Meter

GBFans thread: http://www.gbfans.com/forum/viewtopic.php?f=5&t=43258

Video of how the meter looks when finished

https://www.youtube.com/watch?v=xTfZLYqommg

I have also included the eagle cad files that I used to produce an LED board for this project. OshPark is an amazing place to get custom PCB's fabricated and they will take the brd file as is. I ended up using a buck converter to power the servo so the path with the capacitor was no longer needed. That saved some space but the board was already in fab. 

Image of the internals
https://i1.wp.com/vineripesoftware.files.wordpress.com/2017/05/img_20170508_222438829.jpg

I recommend using hitec servo wire if you can get your hands on it for the wings. I printed everything at .3mm resolution with 20% infill. This print requires a lot of support and there is no way around it.

It's based off this model on Thingiverse (https://www.thingiverse.com/thing:700251) I scaled it up to 110%, removed a few buttons to make it easier to use for my son, and created a new battery holder for the 4 AAA's that power it. I decided on an Arduino nano as the brains with a cheap LCD for display. Again, not going for screen accurate but something that will keep a 6-7 year old entertained. I did program in the Ghostbusters 2 LED pattern for the wings. 

