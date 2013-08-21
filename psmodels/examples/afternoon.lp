
cinema x beach :- not hot.
beach x cinema :- hot.

hot :- not -hot, summer.

-beach :- rain.

summer.
rain.

% Activate lparse classical negation support and preferences
#option --true-negation --priorities.

% Typical command lines:
% lparse --priorities afternoon.lp > /tmp/out
% psmodels 0 /tmp/out
