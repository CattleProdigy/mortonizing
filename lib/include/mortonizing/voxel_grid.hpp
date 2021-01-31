#ifndef VOXEL_GRID_HPP
#define VOXEL_GRID_HPP

#include <morton.h>

#include <cstdint>
#include <vector>

class LinearIndex {
public:
    LinearIndex(uint32_t xDim, uint32_t yDim, uint32_t /*zDim*/)
        : m_xDim(xDim)
        , m_xyDim(xDim * yDim)
    {
    }

    uint32_t idx(uint32_t x, uint32_t y, uint32_t z) const noexcept
    {
        return z * m_xyDim + y * m_xDim + x;
    }

private:
    uint32_t m_xDim;
    uint32_t m_xyDim;
};

class MortonIndex {
public:
    MortonIndex(uint32_t xDim, uint32_t yDim, uint32_t /*zDim*/)
        : m_xDim(xDim)
        , m_xyDim(xDim * yDim)
    {
        // TODO check for powers of two
    }

    uint32_t idx(uint32_t x, uint32_t y, uint32_t z) const noexcept
    {
        return libmorton::morton3D_32_encode(x, y, z);
    }

private:
    uint32_t m_xDim;
    uint32_t m_xyDim;
};

template <typename T, typename Indexing = LinearIndex>
class VoxelGrid {
public:
    VoxelGrid(uint32_t xDim, uint32_t yDim, uint32_t zDim, T def = T())
        : m_indexer(xDim, yDim, zDim)
        , m_data(xDim * yDim * zDim, def)
    {
    }

    const T& at(uint32_t x, uint32_t y, uint32_t z) const
    {
        return m_data.at(m_indexer.idx(x, y, z));
    }
    T& at(uint32_t x, uint32_t y, uint32_t z)
    {
        return m_data.at(m_indexer.idx(x, y, z));
    }

    const T& operator[](uint32_t idx) const
    {
        return m_data.at(idx);
    }
    T& operator[](uint32_t idx)
    {
        return m_data.at(idx);
    }

    uint32_t size() const
    {
        return static_cast<uint32_t>(m_data.size());
    }

private:
    Indexing m_indexer;
    std::vector<T> m_data;
};

#endif // VOXEL_GRID_HPP
