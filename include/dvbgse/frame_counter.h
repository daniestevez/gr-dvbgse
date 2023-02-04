/* -*- c++ -*- */
/*
 * Copyright 2023 Daniel Estevez <daniel@destevez.net>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DVBGSE_FRAME_COUNTER_H
#define INCLUDED_DVBGSE_FRAME_COUNTER_H

#include <gnuradio/sync_block.h>
#include <dvbgse/api.h>

namespace gr {
namespace dvbgse {

/*!
 * \brief Frame Counter
 * \ingroup dvbgse
 *
 * Counts frames of a fixed size, outputting a message per frame.
 */
class DVBGSE_API frame_counter : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<frame_counter> sptr;

    /*!
     * \brief Creates a Frame Counter block.
     *
     * \param item_size Stream item size.
     * \param frame_size Frame size in items.
     */
    static sptr make(size_t itemsize, size_t frame_size);
};

} // namespace dvbgse
} // namespace gr

#endif /* INCLUDED_DVBGSE_FRAME_COUNTER_H */
