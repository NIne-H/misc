#!/bin/bash
# this is meant in jest and I hope nobody gets hurt
# but it should really make loki fucking tiny

$INFO_1="fucking tiny loki"
$INFO_2="a bash script by nine"
$INFO_3="choose your destiny"
$INFO_4="-h : hold the destruction and parley"
$INFO_5="-f : keep international fonts"
$INFO_6='-d : keep "daddy mode"'
$INFO_7="-r : robot waifus"
$INFO_8="-l : the languages you'll never learn..."

echo " - *** - | clearing out 2,000+ copies of the GPL"
rm /usr/share/doc/*/copyright

echo " - *** - | so long non-english fonts"
apt remove fonts-arphic-ukai

echo " - *** - | farewell non-english languagepacks"
apt remove language-pack*

echo " - *** - | bunch of foreign dictionaries"
apt remove wbulgarian \
    wcatalan
    wdanish
    wdutch
    wnorweigian \
    wpolish \
    wswedish \
    wukrainian

echo " - *** - | getting rid of everything but the terminal"
apt remove appcenter \
    apport* \
    appstream* \
    audience* \
    cups* \
    elementary-printer-test-page \
    emacsen-common \
    epiphany-browser* \
    espeak-data \
    flashplugin-installer \
    freepats \
    genisoimage \
    geoclue* \
    gnome-accessiblity-themes \
    gnome-font-viewer \
    gnome-orca \
    gstreamer* \
    hplip \
    libcd* \
    libfluidsynth1 \
    maya-calendar* \
    mysql-common \
    printer-driver* \
    simple-scan \
    switchboard-plug-a11y \
    switchboard-plug-gcc-wacom \
    switchboard-plug-locale \
    switchboard-plug-parental-controls \
    switchboard-plug-printers \
    system-config-printer* \
    ubiquity-slideshow-elementary \
    unity-control-center \
    unity-control-center-faces \
    #unity-settings-daemon \
    update-notifier-common \
    x11-apps \
    zenity*
    
apt autoremove -y
