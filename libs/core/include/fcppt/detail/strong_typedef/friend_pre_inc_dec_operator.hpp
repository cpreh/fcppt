//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_PRE_INC_DEC_OPERATOR_HPP_INCLUDED
#define FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_PRE_INC_DEC_OPERATOR_HPP_INCLUDED


#define FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_PRE_INC_DEC_OPERATOR(\
	op\
)\
template<\
	typename OtherT,\
	typename OtherTag\
>\
friend \
fcppt::strong_typedef<\
	OtherT,\
	OtherTag\
> & \
operator op(\
	fcppt::strong_typedef<\
		OtherT,\
		OtherTag\
	> &\
);

#endif
