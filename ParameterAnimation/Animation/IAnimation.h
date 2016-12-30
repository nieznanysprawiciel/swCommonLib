#pragma once
/**
@file IAnimation.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

/**@defgroup KeyFrameAnimation Keyframe Animation
Animation of rttr properties.
@ingroup CommonFiles*/




/**@brief Base animation class.

Allows such operation like evaluating animations without knowing type.
@ingroup KeyFrameAnimation*/
class IAnimation
{
private:
protected:
public:
	explicit		IAnimation() = default;
	virtual			~IAnimation() = default;

};


