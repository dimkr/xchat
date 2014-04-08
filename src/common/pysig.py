import string
import sys
import re

ens = ""

bbreak = re.compile ("[^A-Z]*,?([A-Z_0-9]+)[^A-Z]*,?")

def process(l):
	global ens
	
	ens = ens + l[:-1]

processing = 0

l = sys.stdin.readline ()
while (l != ""):
	if (string.find (l, "//STOP") != -1):
		processing = 0

	if (processing == 1):
		process(l)

	if (string.find (l, "//START") != -1):
		processing = 1
	l = sys.stdin.readline ()


#print ens

parts1 = []
parts2 = []

parts1 = bbreak.split (ens)
for x in range (len(parts1)):
	if (x & 1 == 1):
		parts2.append (parts1[x])
print parts2

print """/* XChat
   This file was generated by sigextract.py by Adam Langley
   agl@linuxpower.org

   It should *not* be edited by hand!

   AGL
*/

struct signalmapping
{
   char *name;
   int num;
};

static struct signalmapping signal_mapping[] = {
"""

# This is the start of the numbers, in this case the signals start at 1
count = 1

for x in parts2:
	print "   {\"" + x + "\", " + str(count) + "},"
	count = count + 1

print """
   {NULL, 0}
};


#define NUM_SIGNALS_LOOKUP """,
print str(count)
