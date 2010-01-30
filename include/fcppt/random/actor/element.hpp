//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_ACTOR_ELEMENT_HPP_INCLUDED
#define FCPPT_RANDOM_ACTOR_ELEMENT_HPP_INCLUDED

#include <fcppt/random/actor/element_fwd.hpp>
#include <fcppt/random/actor/float_type.hpp>
#include <fcppt/random/actor/callback.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/symbol.hpp>

namespace fcppt
{
namespace random
{
namespace actor
{

class element
{
public:
	FCPPT_SYMBOL element(
		float_type,
		actor::callback const &
	);

	FCPPT_SYMBOL float_type const &
	prob() const;

	FCPPT_SYMBOL actor::callback const &
	callback() const;
private:
	float_type prob_;
	actor::callback callback_;
};

}
}
}

#endif
