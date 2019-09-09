/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.js                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:23:48 by amartino          #+#    #+#             */
/*   Updated: 2019/07/03 19:25:30 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react';
import {
  AppRegistry, StyleSheet, Text, View, ScrollView, Animated, Image,
  Dimensions, TouchableOpacity, Button
} from 'react-native';
import Modal from "react-native-modal";
import MapView from 'react-native-maps';
import ArticleItem from './../ArticleItem/ArticleItem'
import findMe from './findMe'
import Search from './Search';
import { graphql} from 'react-apollo';
import gql from 'graphql-tag';

const { width, height } = Dimensions.get("window");

const CARD_HEIGHT = height / 5;
const CARD_WIDTH = width / 2;

class Map extends React.Component {
	constructor(props) {
		super(props)
		this.state = {
	    region: {
	      latitude: 48.8566905,
	      longitude: 2.3467233,
	      latitudeDelta: 0.04864195044303443,
	      longitudeDelta: 0.040142817690068,
      },
			markers: [],
      isModalVisible: false
	};
	this._applySearchFilter = this._applySearchFilter.bind(this)
	this._toggleModal = this._toggleModal.bind(this)
}

	componentWillMount() {
    this.index = 0;
    this.animation = new Animated.Value(0);
  }

  componentDidMount() {
    this.animation.addListener(({ value }) => {//
      let index = Math.floor((value + CARD_WIDTH) / CARD_WIDTH - 0.1);//
			if (index >= this.props.data.getArticles.length) {//
        index = this.props.data.getArticles.length - 1;//
      }
      if (index <= 0) {//
        index = 0;//
      }

			clearTimeout(this.regionTimeout);
      this.regionTimeout = setTimeout(() => {
        if (this.index !== index) {
          this.index = index;
          this[index].showCallout();
        }
      }, 10);
    });

		findMe().then(data => {
			if (data === 'Permissoin to access location was denied') {
				this.setState({
					region: {
						...this.state.region,
						latitude: 48.8615682,
						longitude: 2.3801912,
					},
					markers: this.props.data.getArticles
				})
			} else if (data === 'error tmp') {
				//gestion d'erreur à faire
			} else {
				if (this.state.region.latitude !== data.latitude
					|| this.state.region.longitude !== data.longitude) {
					this.setState({
						region: {
							...this.state.region,
							latitude: data.latitude,
							longitude: data.longitude
						},
						markers: this.props.data.getArticles
					});
				}
			}
		})
  }

  _toggleModal() {
    this.setState({ isModalVisible: !this.state.isModalVisible });
  };

  _applySearchFilter(filteredArticles) {
    this.setState({
      markers: filteredArticles,  //WARNING makers does not exist anymore
			isModalVisible: !this.state.isModalVisible
    })
  }

	_displayDetailForArticle = (article) => {
		this.props.navigation.navigate("ArticleDetail", { article: article })
	}

	render() {
		const { markers } = this.state;
    return (

      <View style={styles.container}>


        <MapView
          ref={map => this.map = map}
          region={this.state.region}//
          style={styles.container}
					showsUserLocation
					showsMyLocationButton
					loadingEnabled={true}
        >
					{markers.map((marker, index) => {
						const { name } = marker.subCategory.category
					  return (
					    <MapView.Marker
								key={index}
								ref={(ref) =>  this[index] = ref}
								coordinate={marker.coordinates}
								title={marker.name}
								pinColor={
									name === "Par'Appetit"     ? 'green'  :
									name === "Par'Ivresse"     ? 'blue'   :
									name === "Par'Gourmandise" ? 'gold'   :
									name === "Par'Passion"     ? 'purple' :
									name === "Par'Ailleurs"    ? 'orange' : red
								}
								onPress={elem => {
									this.scroll.scrollTo({x: (index * CARD_WIDTH - 100), y: 0, animated: false})
								}}
							/>
					  );
					})}
        </MapView>


        <TouchableOpacity
          style={styles.advanced_search}
          onPress={this._toggleModal}>
          <Image
            style={styles.icon}
            source={require("../../assets/search.png")}
          />
          <Modal
            style={styles.modal}
            isVisible={this.state.isModalVisible}
          >
            <Search
              applySearchFilter={this._applySearchFilter}
              articles={this.props.data.getArticles}
            />
          </Modal>
        </TouchableOpacity>

        <ScrollView ///////////////////////////////////////////////
					ref={(ref) => { this.scroll = ref }}
          horizontal//
          scrollEventThrottle={0}//
          showsHorizontalScrollIndicator={false}//
          snapToInterval={CARD_WIDTH}//ios only
					snapToAlignment={'center'}
          onScroll={Animated.event(
            [
              {
                nativeEvent: {
                  contentOffset: {
                    x: this.animation,
                  },
                },
              },
            ]
          )}
          style={styles.scrollView}//
          contentContainerStyle={styles.endPadding}//
        >
          {markers.map((marker, index) => (
						<ArticleItem
							article={marker}
							key={index}
							displayDetailForArticle={this._displayDetailForArticle}
							card_height={CARD_HEIGHT}
							card_width={CARD_WIDTH}
						/>
          ))}
        </ScrollView>
      </View>
    );
	  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  scrollView: {
    position: "absolute",
    bottom: 30,
    left: 0,
    right: 0,
    paddingVertical: 10,
  },
  endPadding: {
    paddingRight: width - CARD_WIDTH,
  },
  card: {
    padding: 10,
    elevation: 2,
    backgroundColor: "#FFF",
    marginHorizontal: 10,
    shadowColor: "#000",
    shadowRadius: 5,
    shadowOpacity: 0.3,
    shadowOffset: { x: 2, y: -2 },
    height: CARD_HEIGHT,
    width: CARD_WIDTH,
    overflow: "hidden",
  },
  cardImage: {
    flex: 3,
    width: "100%",
    height: "100%",
    alignSelf: "center",
  },
  textContent: {
    flex: 1,
  },
  cardtitle: {
    fontSize: 12,
    marginTop: 5,
    fontWeight: "bold",
  },
  cardDescription: {
    fontSize: 12,
    color: "#444",
  },
  markerWrap: {
    alignItems: "center",
    justifyContent: "center",
  },
  marker: {
    width: 8,
    height: 8,
    borderRadius: 4,
    backgroundColor: "rgba(130,4,150, 0.9)",
  },
  ring: {
    width: 24,
    height: 24,
    borderRadius: 12,
    backgroundColor: "rgba(130,4,150, 0.3)",
    position: "absolute",
    borderWidth: 1,
    borderColor: "rgba(130,4,150, 0.5)",
  },
  icon: {
    height: 30,
		width: 30,
    resizeMode: 'contain',
  },
  advanced_search: {
    position: "absolute",
    top: 20,
    right: 20,
  },
  modal: {
    flex: 1,
    backgroundColor: "rgba(255,255,255, 1)",
    margin: 0,
  }
});

const QueryArticles = gql`
	query {
		getArticles {
			id
			name
			adress
			arrondissement
			openings
			openingsSecondLine
			tel
			metro
			isFavorite
			metroImgUrls
			imgUrls
			thumbnailUrl
			latitude
			longitude
			coordinates {
				latitude
				longitude
			}
			subCategory {
				id
				name
				category {
					id
					name
				}
			}
			price
			weblink
			text
			updatedAt
			createdAt
		}
	}
`;

export default graphql(QueryArticles)(Map);
