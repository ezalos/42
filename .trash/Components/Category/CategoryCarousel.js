/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CategoryCarousel.js                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:15:47 by root              #+#    #+#             */
/*   Updated: 2019/07/04 21:30:55 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { StyleSheet, View, Text, FlatList, ActivityIndicator, Image, TouchableOpacity, Shadow, Button } from 'react-native';
import articles from '../../Helpers/db';
import ArticleItem from './../ArticleItem/ArticleItem'
import SubcategoryHeader from './SubcategoryHeader'
import { buttons, adders, images } from '../../styles/style.js'
import { Container, Spacer, Row, CategoryShortcuts } from './../basic/view.js'
import { colors, borderRadius, fonts, icon, image, padding, margin, dimensions, fontsSize, fontsWeight, fontsFamily } from '../../styles/base.js'
import { graphql} from 'react-apollo';
import gql from 'graphql-tag';


// import { LinearGradient } from 'expo-linear-gradient';
// 	<LinearGradient
// 	  colors={['#4c669f', '#3b5998', '#192f6a']}
// 	  style={{ padding: 15, alignItems: 'center', borderRadius: 5 }}
// 	>
// 	</LinearGradient>

class CategoryCarousel extends React.Component {

	_displayDetailForArticle = (article) => {
		this.props.navigation.navigate("ArticleDetail", { article: article })																	// seulement idFilm
	}

	_displaySubCategory = (articles, subCategoryTitle) => {
		this.props.navigation.navigate("SubCategory", { articles: articles, subCategoryTitle : subCategoryTitle })																	// seulement idFilm
	}

	_displayLoading() { 																												//underscore pour indiquer que la méthode est privée. this._displayLoading => OK | search._loadFilms => not OK even if it's working
		if (this.state.isLoading) {
			return (
				<View style={styles.loading_container}>
					<ActivityIndicator size='large' />
				</View>
			)
		}
	}

  render () {
		const { categories } = this.props.data
		const { subCategoryTitle, categoryValue, subCategoryId } = this.props
		let subCategoryValue;
		subCategoryValue = categories[categoryValue].subCategories.findIndex(tmp => tmp.id === subCategoryId)
		return (
			<Container>
					<View style={[styles.sideList]}>
						<SubcategoryHeader subCategoryTitle={subCategoryTitle} displaySubCategory={this._displaySubCategory} articles={categories[categoryValue].subCategories[subCategoryValue].articles}/>
						<FlatList
							horizontal
							data={categories[categoryValue].subCategories[subCategoryValue].articles}
							keyExtractor={(item) => item.id.toString()}
							renderItem={({item}) => (
								<Container>
									<ArticleItem
										article={item}
										displayDetailForArticle={this._displayDetailForArticle}
										card_height={image.md_h}
										card_width={image.xl_w - (image.xl_w / 6)}
									/>
								</Container>
							)}
						/>
						<View style={styles.spacing}/>
					</View>
			</Container>
		)
	}

}

const styles = StyleSheet.create({

		main_container: {																															//By default flexDirection is column
			flex: 1
		},
		scrollview_container: {
		flex: 1
		},
		spacing: {
			height: 1
		},
  		end_spacer: {
  			height: 30,
  		},
		sideList: {
			flexDirection: 'column',
		},
		loading_container: {
			position: 'absolute',
			left: 0,
			right: 0,
			top: 90,
			bottom: 0,
			alignItems: 'center',																												//alignItem is on the horizontal axis X (when flexDirection=Column)
			justifyContent: 'center'																										//justifyContent is on the vertical axis Y
		}
})

const QueryCategories = gql`
	query {
		categories {
			id
			name
			subCategories {
				id
				name
				category{
					id
					name
				}
				articles {
					id
					name
					adress
					arrondissement
					isFavorite
					openings
					openingsSecondLine
					tel
					metro
					metroImgUrls
					imgUrls
					thumbnailUrl
					latitude
					longitude
					price
					weblink
					text
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
					updatedAt
					createdAt
				}
			}
		}
	}
`;

export default graphql(QueryCategories)(CategoryCarousel);

// const QueryCategories = gql`
// 	query ($name: String!){
// 		getCategory (name: $name){
// 			id
// 			name
// 		 	subCategories {
// 			 	id
// 			 	name
// 				articles (last: 1) {
// 					id
// 					name
// 					arrondissement
// 					isFavorite
// 					thumbnailUrl
// 					price
// 				}
// 		 	}
// 		}
// 	}
// `;
//
// export default graphql(QueryCategories, {
//  options: (props) => ({ variables: { name: props.navigation.state.params.categoryTitle} })
// })(CategoryCarousel);
