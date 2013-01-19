//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_FUSION_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_FUSION_HPP_INCLUDED

#include <fcppt/container/array_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/boost_array.hpp>
#include <boost/fusion/support/tag_of_fwd.hpp>
#include <boost/mpl/sequence_tag_fwd.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace boost
{
namespace fusion
{

struct boost_array_tag;
struct fusion_sequence_tag;

namespace traits
{
        template<
		typename T,
		std::size_t N
	>
	struct tag_of<
		fcppt::container::array<
			T,
			N
		>
	>
        {
		typedef boost_array_tag type;
	};
}
}

namespace mpl
{

template<
	typename T,
	std::size_t N
>
struct sequence_tag<
	fcppt::container::array<
		T,
		N
	>
>
{
	typedef fusion::fusion_sequence_tag type;
};

template<
	typename T,
	std::size_t N
>
struct sequence_tag<
	fcppt::container::array<
		T,
		N
	> const
>
{
	typedef fusion::fusion_sequence_tag type;
};

}
}

#endif
