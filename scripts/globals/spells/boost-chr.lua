--------------------------------------
-- 	Spell: Boost-CHR
-- 	Boosts CHR for Allies in AoE
--------------------------------------
 
require("scripts/globals/settings");
require("scripts/globals/status");
require("scripts/globals/magic");

-----------------------------------------
-- OnSpellCast
-----------------------------------------

function OnMagicCastingCheck(caster,target,spell)
	return 0;
end;

function onSpellCast(caster,target,spell)
	local effect = EFFECT_CHR_BOOST;
	doBoostGain(caster,target,spell,effect);
	return effect;
end;