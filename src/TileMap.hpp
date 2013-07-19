#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief A tile-based map
 *
 * The tile data is stored as a multi dimensional vector of tile ids.
 * The special id '0' stands for 'air', a.k.a 'empty' tile.
 */
class TileMap
{
public:
    TileMap();

    void LoadTiles();

    void Resize(unsigned int new_hLength, unsigned int new_vLength);
    void SetTile(unsigned int x, unsigned int y, unsigned int id);
    unsigned int GetTile(unsigned int x, unsigned int y) const;

    /**
     * @brief Fill the map with a specific tile
     * @param id The tile to fill the map with. If it is 0, the function will
     *           fill the map with empty tiles, i.e. clear the map.
     */
    void Fill(unsigned int id);

    void Move(int x_offset, int y_offset);
    void SetPosition(int new_x_coord, int new_y_coord);

    unsigned int GetHLength() const;
    unsigned int GetVLength() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

    void Draw(sf::RenderWindow &w);

    bool TileExists(unsigned int x, unsigned int y) const;
    bool SpriteExists(unsigned int id) const;

private:
    static const int GRID_SIZE = 40;
    std::vector< std::vector<unsigned int> > map;
    unsigned int hLength, vLength, width, height;

    std::vector< sf::Sprite > sprites;
    sf::Texture tileSet;

    int x_coord, y_coord;

};

#endif // TILEMAP_HPP
