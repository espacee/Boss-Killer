#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

#include "Layer.hpp"

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

    void ResizeLayer(unsigned int layer, unsigned int new_hLength, unsigned int new_vLength);
    void SetTile(unsigned int x, unsigned int y, unsigned int layer, unsigned int id);
    unsigned int GetTile(unsigned int x, unsigned int y, unsigned int layer) const;

    /**
     * @brief Fill the map with a specific tile
     * @param id The tile to fill the map with. If it is 0, the function will
     *           fill the map with empty tiles, i.e. clear the map.
     */
    void FillLayer(unsigned int layer, unsigned int id);

    void MoveLayer(int x_offset, int y_offset, unsigned int layer);
    void SetLayerPosition(int new_x_coord, int new_y_coord, unsigned int layer);

    void AddLayer();
    void PopLayer();

    bool TileExists(unsigned int x, unsigned int y, unsigned int layer) const;
    bool SpriteExists(unsigned int id) const;
    bool LayerExists(unsigned int layer) const;

private:
    std::vector< Layer > layers;
    unsigned int nb_layers;
    unsigned int lastLayerID;

    std::vector< sf::Sprite > sprites;
    sf::Texture tileSet;

    int x_coord, y_coord;

};

#endif // TILEMAP_HPP
