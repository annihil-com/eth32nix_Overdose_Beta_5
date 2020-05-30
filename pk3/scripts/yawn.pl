#!/usr/bin/perl
use strict;
use LWP::Simple;
use IO::Socket;
$|=1;

if (!-e "$ENV{HOME}/.etwolf/etmain/guid.cfg") {
     my $script = "set guidcheck \"clear; wait 130;guids; wait 130;condump guidcheck.txt\"\nvstr guidcheck";
     open SC, ">$ENV{HOME}/.etwolf/etmain/guid.cfg";
     print SC $script;
     close SC;
     print "et_str<exec guid>et_end";
     print "Use /vstr guidcheck to get a list of guids. then /!yawn ID";
     exit
}
my ($yawn,$data);

if ($ARGV[0] eq 'nick') {
     $yawn = "http://yawn.be/findPlayer.yawn?nick=$ARGV[1]&pbGuid=&etproGuid=&gamecode=ET";
     parse($data) if check() == 1
}

if ($ARGV[0] eq 'guid') {
     sysopen(FH,"$ENV{HOME}/.etwolf/etpro/guidcheck.txt",'O_RDNLY');
     sysread(FH,my $buf,2**16);
     my @list = split /\n/,$buf;
     my ($name,$guid);
     foreach my $line (0..$#list) {
         if ($list[$line] =~ /^$ARGV[1]\s\[(.*?)]\s\[(.*?)\]/) {
             $name = $1;
             $guid = $2;
             $name =~ s/\^.//g;
             print "User $name with guid $guid; Searching yawn now..\n"
         }
     }
     $yawn = "http://yawn.be/findPlayer.yawn?nick=&pbGuid=&etproGuid=$guid&gamecode=ET";
     parse($data) if check() == 1
}

sub check {
     if (IO::Socket::INET->new(PeerAddr=>'yawn.be',PeerPort=>80,Proto=>'tcp')) {
         $data = get($yawn);
         return 1
     }
     else {
         print "Can't connect to yawn.\n";
         return 0
     }
}

sub parse {
     while ($_[0] =~ /<tr class="(odd|even)">(.*?)<\/tr>/gs) {
         my $info = $2;
         $info =~ s/(<td.*?>|<strong>|<font color=".*?">|<\/font>|<\/strong>|<\/td>|<a.*?>|<\/a>|<img.*?>)//g;
         my @player = split /\n/, $info;
         print "$player[2] \t $player[1]\n"
     }
     if ($_[0] =~ /Nothing found to display./) {
         print "Nothing found to display.\n"
     }
}
