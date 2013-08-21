c_1 : ice_cream x cake.
c_2 : coffee x tea.

 :- ice_cream, coffee.

% Having ice cream is more important to having coffee, if we are
% choicy. 
priority(c_1, c_2) :- choicy.

choicy.


% Typical command lines:
% lparse --priorities meta_dessert.lp > /tmp/out
% psmodels 0 /tmp/out

% Set lparse command line options automatically:
#option --priorities
