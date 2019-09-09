/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.js                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:00:21 by amartino          #+#    #+#             */
/*   Updated: 2019/07/03 15:45:31 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react';
import {
  Text, View, SafeAreaView, Button, StyleSheet, TouchableOpacity, Image
} from 'react-native'
import {
	Container, Spacer, Row, CategoryShortcuts, RowSA, AdditionalInfo,
	WrapRow, ArticleBox
} from './../basic/view.js'
import { Title, Header, Description } from './../basic/text.js'
import MapParis from './MapParis.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'

let filteredArticlesByPrice = [];
let filteredArticlesByDistrict = [];
let filteredArticlesByCategory = [];

let arg = [
  [],
  [],
	[]
]

class Search extends React.Component {

  _filterPrice(PriceElem) {
    let tmp;
    tmp = this.props.articles.filter(
      (item) => {
        return item.price == PriceElem;
      }
    )
    filteredArticlesByPrice = [ ...filteredArticlesByPrice, ...tmp ]
  }

  _filterDistrict(districtElem) {
    let tmp;
    let tmp2 = filteredArticlesByPrice
    tmp = tmp2.filter(
      (item) => {
        return item.arrondissement === districtElem;
      }
    )
    filteredArticlesByDistrict = [ ...filteredArticlesByDistrict, ...tmp ]
  }

	_filterCategory(categoryelem) {
		let tmp;
		let tmp2 = filteredArticlesByDistrict
		tmp = tmp2.filter(
			(item) =>  {
				return item.category === categoryelem;
			}
		)
		filteredArticlesByCategory = [ ...filteredArticlesByCategory, ...tmp ]
	}

  _searchFilter() {
		filteredArticlesByPrice = [];
		filteredArticlesByDistrict = [];
		filteredArticlesByCategory = [];
    arg[0].forEach((elem, index) => {
      this._filterPrice(elem)
    })
    arg[1].forEach((elem, index) => {
      this._filterDistrict(elem)
    })
		arg[2].forEach((elem, index) => {
			this._filterCategory(elem)
		})
    this.props.applySearchFilter(
			filteredArticlesByCategory.length > 0 ?
				filteredArticlesByCategory : filteredArticlesByDistrict.length > 0 ?
					filteredArticlesByDistrict : filteredArticlesByPrice.length > 0 ?
						filteredArticlesByPrice : this.props.articles
		)
  }

	_sortingFilter(elem, i) {
		if ((arg[i].some(item => item === elem) === true)) {
			arg[i] = arg[i].filter(
				(item) => {
					return item !== elem;
				}
			)
		}
		else {
			arg[i].push(elem)
		}
		console.log(arg);
	}

  render() {
    const { applySearchFilter, articles } = this.props
    return (
		<SafeAreaView style={{flex: 1}}>
			<Title>Advanced Search</Title>
	        <View style={styles.searchModal}>
				<CategoryShortcuts intermediateCategoryAccess={this._category}/>
				<Image
					style={
						{
							flex: 1,
							width: dimensions.xl_w,
							height: dimensions.xl_w,
							resizeMode: 'contain',
						}}
					source={require("../../assets/good/MapParis.png")}
				/>
				<View style={styles.mapCombo}>
					<MapParis style={styles.mapImage}/>
					<Image
						style={styles.mapImage}
						source={require("../../assets/good/MapParis.png")}
					/>
				</View>
				<View style={{flex: 1, margin: 20}}>
					<RowSA>
						<TouchableOpacity
							onPress={ () => this._sortingFilter(1, 0) }
						>
							<Text style={{fontSize: 50}}>€</Text>
						</TouchableOpacity>
						<TouchableOpacity
							onPress={ () => this._sortingFilter(2, 0) }
						>
							<Text style={{fontSize: 50}}>€€</Text>
						</TouchableOpacity>
						<TouchableOpacity
							onPress={ () => this._sortingFilter(3, 0) }
						>
							<Text style={{fontSize: 50}}>€€€</Text>
						</TouchableOpacity>
					</RowSA>
				</View>
		  	</View>
		  <Button title="Activate Filters" onPress={this._searchFilter.bind(this)} />
        </SafeAreaView>
    )
  }
}

const styles = StyleSheet.create({
  searchModal: {
    flex: 1,
	justifyContent: 'space-between',
  },
  mapImage: {
	  flex: 1,
	  position: 'absolute',
	  top: 0,
	  left: 0,
	  resizeMode: 'contain',
  },
  mapCombo: {
	  flex: 1,
  },
	category:{
		flex:1,
    flexDirection: 'column',
    justifyContent: 'center',
		alignItems: 'center',
		borderRadius:1,
		marginHorizontal:1,
		marginVertical:1,
		height: 45,
		width: 45,
		borderRadius:100,
  },
	icon: {
		flex:1,
		position: 'absolute',
		height: 40,
		width: 40,
    resizeMode: 'contain',
  }
});

export default Search
