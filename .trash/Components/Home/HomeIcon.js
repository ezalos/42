/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HomeIcon.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:54:45 by amartino          #+#    #+#             */
/*   Updated: 2019/06/05 15:55:23 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { StyleSheet, View, Text, Image, TouchableOpacity, Shadow, Button } from 'react-native';

class HomeIcon extends React.Component {

  render () {
    const { img, categoryTitle, categoryAccess, color } = this.props
    return (

      <TouchableOpacity
         style={styles.category}
         activeOpacity = { .5 }
         onPress={ () => categoryAccess(categoryTitle) }
      >
		        <Image
		          style={styles.icon}
		          source={img}
		        />
      </TouchableOpacity>
    )
  }

}

const styles = StyleSheet.create({
  category:{
		flex:1,
    flexDirection: 'column',
    justifyContent: 'center',
		alignItems: 'center',
		borderRadius:1,
		marginHorizontal:1,
		marginVertical:1,
		// 	shadowOpacity:1,
		// 	shadowRadius: 10,
		// 	elevation: 3,
		// 	shadowColor: 'black',
		// backgroundColor: 'rgba(245,245,245,1)',
		height: 45,
		width: 45,
		borderRadius:700,
  },
  icon: {
		flex:1,
		height: undefined,
		width: undefined,
		height: 40,
		width: 40,
    resizeMode: 'contain',
  }
})

export default HomeIcon
