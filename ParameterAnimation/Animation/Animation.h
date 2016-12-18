#pragma once
/**
@file Animation.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/


#include "Common/ParameterAnimation/Animation/AnimEvaluator.h"

/**@brief */
class Animation
{
private:
protected:
public:
	explicit		Animation() = default;
	virtual			~Animation() = default;

};


/**@brief */
template< typename KeyType, typename AddressType >
class AnimationImpl : public Animation
{
private:
protected:
public:
	AnimEvaluator< KeyType, AddressType >		Evaluator;

public:


};


