#include <fcppt/io/raw_container_source.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/container/raw_vector.hpp>
#include <boost/next_prior.hpp>
#include <algorithm>
#include <iterator>

fcppt::io::raw_container_source::raw_container_source(
	char const * begin,
	char const * end)
:
	chars_(
		fcppt::make_shared_ptr<container>(
			begin,
			end)),
	pos_(
		chars_->begin())
{
}

std::streamsize
fcppt::io::raw_container_source::read(
	char * const s,
	std::streamsize const n)
{
	std::streamsize const result = 
		std::min(
			n, 
			std::distance(
				pos_,
				chars_->cend()));

	// EOF
	if (result == 0u) 
		return -1;

	const_iterator const new_pos = 
		boost::next(
			pos_,
			result);

	std::copy(
		pos_,
		new_pos,
		s);

	pos_ = new_pos;
	return result;
}

std::streampos 
fcppt::io::raw_container_source::seek(
	boost::iostreams::stream_offset const off, 
	std::ios_base::seekdir const way)
{
	switch (way)
	{
		case std::ios_base::beg:
			pos_ = 
				boost::next(
					chars_->cbegin(),
					off);
			break;
		case std::ios_base::cur:
			pos_ = 
				boost::next(
					pos_,
					off);
			break;
		case std::ios_base::end:
			pos_ =
				boost::prior(
					chars_->cend(),
					off);
			break;
		default: break;
	}
	return 
		std::distance(
			chars_->cbegin(),
			pos_);
}
