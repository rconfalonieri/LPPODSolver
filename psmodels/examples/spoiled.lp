% Give either cake or ice-cream. 
1 { ice_cream, cake } 1.

% Prefer ice cream, if given cake. Otherwise prefer cake. 
ice_cream x cake :- cake.
cake x ice_cream :- ice_cream.

% Typical command lines:
% lparse --priorities spoiled.lp > /tmp/out
% psmodels 0 /tmp/out

% Set lparse command line options automatically:
#option --priorities

