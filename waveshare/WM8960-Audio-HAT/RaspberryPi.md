### WM8960-Audio-HAT on Raspberry Pi Model 3B+

![24821703725072_ pic](https://github.com/josthlee/IoT-Quickstart/assets/154501794/2648098f-ba52-48b7-93e6-65e5332e4719)

### System update and upgrade

```
root@raspberrypi:/home/pi# uname -a
Linux raspberrypi 6.1.0-rpi7-rpi-v8 #1 SMP PREEMPT Debian 1:6.1.63-1+rpt1 (2023-11-24) aarch64 GNU/Linux
root@raspberrypi:/home/pi# apt-get update
Hit:1 http://deb.debian.org/debian bookworm InRelease
Hit:2 http://deb.debian.org/debian-security bookworm-security InRelease
Get:3 http://deb.debian.org/debian bookworm-updates InRelease [52.1 kB]
Hit:4 http://archive.raspberrypi.com/debian bookworm InRelease              
Fetched 52.1 kB in 3s (16.6 kB/s)
Reading package lists... Done
root@raspberrypi:/home/pi# apt-get upgrade
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
Calculating upgrade... Done
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.
```

### Comment out built-in audio in /boot/config.txt

```
#dtparam=audio=on
```

### Install git if there is none

```
root@raspberrypi:/home/pi# apt-get install git
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
The following additional packages will be installed:
  git-man liberror-perl
Suggested packages:
  git-daemon-run | git-daemon-sysvinit git-doc git-email git-gui gitk gitweb git-cvs git-mediawiki git-svn
The following NEW packages will be installed:
  git git-man liberror-perl
0 upgraded, 3 newly installed, 0 to remove and 0 not upgraded.
Need to get 9101 kB of archives.
After this operation, 47.9 MB of additional disk space will be used.
Do you want to continue? [Y/n] 
Get:1 http://deb.debian.org/debian bookworm/main arm64 liberror-perl all 0.17029-2 [29.0 kB]
Get:2 http://deb.debian.org/debian bookworm/main arm64 git-man all 1:2.39.2-1.1 [2049 kB]
Get:3 http://deb.debian.org/debian bookworm/main arm64 git arm64 1:2.39.2-1.1 [7023 kB]
Fetched 9101 kB in 3s (3441 kB/s)
```

### Pull code and make install

```
root@raspberrypi:/home/pi# git clone https://github.com/waveshare/WM8960-Audio-HAT
Cloning into 'WM8960-Audio-HAT'...
remote: Enumerating objects: 79, done.
remote: Counting objects: 100% (41/41), done.
remote: Compressing objects: 100% (17/17), done.
remote: Total 79 (delta 29), reused 25 (delta 24), pack-reused 38
Receiving objects: 100% (79/79), 62.96 KiB | 294.00 KiB/s, done.
Resolving deltas: 100% (38/38), done.
root@raspberrypi:/home/pi# cd WM8960-Audio-HAT/
root@raspberrypi:/home/pi/WM8960-Audio-HAT $ ls
LICENSE    asound.conf   install.sh        wm8960-soundcard.c     wm8960-soundcard.service  wm8960_asound.state
Makefile   builddtbo.sh  uninstall.sh      wm8960-soundcard.dtbo  wm8960.c
README.md  dkms.conf     wm8960-soundcard  wm8960-soundcard.dts   wm8960.h
root@raspberrypi:/home/pi/WM8960-Audio-HAT $ sudo ./install.sh
Hit:1 http://deb.debian.org/debian bookworm InRelease
Hit:2 http://deb.debian.org/debian-security bookworm-security InRelease
Hit:3 http://deb.debian.org/debian bookworm-updates InRelease
Hit:4 http://archive.raspberrypi.com/debian bookworm InRelease
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
All packages are up to date.
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
...
...
...
Creating symlink /var/lib/dkms/wm8960-soundcard/1.0/source -> /usr/src/wm8960-soundcard-1.0
Sign command: /usr/lib/linux-kbuild-6.1/scripts/sign-file
Signing key: /var/lib/dkms/mok.key
Public certificate (MOK): /var/lib/dkms/mok.pub
Certificate or key are missing, generating self signed certificate for MOK...

Building module:
Cleaning build area...
make -j4 KERNELRELEASE=6.1.0-rpi7-rpi-v8 -C /lib/modules/6.1.0-rpi7-rpi-v8/build M=/var/lib/dkms/wm8960-soundcard/1.0/build.......
Signing module /var/lib/dkms/wm8960-soundcard/1.0/build/snd-soc-wm8960.ko
Signing module /var/lib/dkms/wm8960-soundcard/1.0/build/snd-soc-wm8960-soundcard.ko
Cleaning build area...

snd-soc-wm8960.ko.xz:
Running module version sanity check.
 - Original module
 - Installation
   - Installing to /lib/modules/6.1.0-rpi7-rpi-v8/updates/dkms/

snd-soc-wm8960-soundcard.ko.xz:
Running module version sanity check.
 - Original module
 - Installation
   - Installing to /lib/modules/6.1.0-rpi7-rpi-v8/updates/dkms/
depmod.....
Created symlink /etc/systemd/system/sysinit.target.wants/wm8960-soundcard.service → /lib/systemd/system/wm8960-soundcard.service.
Job for wm8960-soundcard.service failed because the control process exited with error code.
See "systemctl status wm8960-soundcard.service" and "journalctl -xeu wm8960-soundcard.service" for details.
------------------------------------------------------
Please reboot your raspberry pi to apply all settings
Enjoy!
```
### Reboot and check results

```
root@raspberrypi:/home/pi# dkms status
wm8960-soundcard/1.0, 6.1.0-rpi7-rpi-v8, aarch64: installed
root@raspberrypi:/home/pi# aplay -l
**** List of PLAYBACK Hardware Devices ****
card 0: vc4hdmi [vc4-hdmi], device 0: MAI PCM i2s-hifi-0 [MAI PCM i2s-hifi-0]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
card 1: wm8960soundcard [wm8960-soundcard], device 0: bcm2835-i2s-wm8960-hifi wm8960-hifi-0 [bcm2835-i2s-wm8960-hifi wm8960-hifi-0]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
root@raspberrypi:/home/pi# arecord -l
**** List of CAPTURE Hardware Devices ****
card 1: wm8960soundcard [wm8960-soundcard], device 0: bcm2835-i2s-wm8960-hifi wm8960-hifi-0 [bcm2835-i2s-wm8960-hifi wm8960-hifi-0]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
```

### Try to arecord and then aplay

* Make some noise and CTRL+C to stop recording

```
root@raspberrypi:/home/pi/WM8960-Audio-HAT# arecord -D hw:1,0 -f S32_LE -r 16000 -c 2 test.wav
Recording WAVE 'test.wav' : Signed 32 bit Little Endian, Rate 16000 Hz, Stereo
^CAborted by signal Interrupt...
```

* Now you can hear the recorded sound from the connected speaker or ear phone

```
root@raspberrypi:/home/pi/WM8960-Audio-HAT# aplay -Dhw:1 test.wav 
Playing WAVE 'test.wav' : Signed 32 bit Little Endian, Rate 16000 Hz, Stereo
```

### Issues and workaround

* WM8960 soundcard service ExecStart=/usr/bin/wm8960-soundcard (code=exited, status=99)

```
pi@raspberrypi:~/WM8960-Audio-HAT $ systemctl status wm8960-soundcard.service
× wm8960-soundcard.service - WM8960 soundcard service
     Loaded: loaded (/lib/systemd/system/wm8960-soundcard.service; enabled; preset: enabled)
     Active: failed (Result: exit-code) since Wed 2023-12-27 17:26:34 CST; 14s ago
    Process: 5018 ExecStart=/usr/bin/wm8960-soundcard (code=exited, status=99)
   Main PID: 5018 (code=exited, status=99)
        CPU: 385ms
```

* Comment out the alsactl restore in /usr/bin/wm8960-soundcard

```
#alsactl restore
```
