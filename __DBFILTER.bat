XCOPY *.H   				..\_INCLUDE\DBFILTER	/Y

xcopy ..\_INCLUDE\DBFILTER  "J:\_INCLUDE\DBFILTER"

XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\BPL\DBFilter250.bpl   "j:\_library\packages\bpl" /Y
XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\BPL\DBFilterR250.bpl  "j:\_library\packages\bpl" /Y
XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\BPL\DBFilterD250.bpl  "j:\_library\packages\bpl" /Y

XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\DCP\DBFilter250.bpi  "j:\_library\packages\lib\" /Y
XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\DCP\DBFilter250.lib  "j:\_library\packages\lib\" /Y
XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\DCP\DBFilterR250.bpi "j:\_library\packages\lib\" /Y
XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\DCP\DBFilterR250.lib "j:\_library\packages\lib\" /Y
XCOPY c:\Users\Public\Documents\Embarcadero\Studio\19.0\DCP\DBFilterD250.lib "j:\_library\packages\lib\" /Y
pause

