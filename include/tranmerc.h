/**
 * \file tranmerc.h
 * \author Zhihao Zhan (zhanzhihao_dt@163.com)
 * \brief TRANSVERSE MERCATOR
 * \version 0.1
 * \date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef TRANMERC_H
#define TRANMERC_H

#include <cmath>
#include <iostream>

#define TRANMERC_NO_ERROR 0x0000
#define TRANMERC_LAT_ERROR 0x0001
#define TRANMERC_LON_ERROR 0x0002
#define TRANMERC_EASTING_ERROR 0x0004
#define TRANMERC_NORTHING_ERROR 0x0008
#define TRANMERC_ORIGIN_LAT_ERROR 0x0010
#define TRANMERC_CENT_MER_ERROR 0x0020
#define TRANMERC_A_ERROR 0x0040
#define TRANMERC_INV_F_ERROR 0x0080
#define TRANMERC_SCALE_FACTOR_ERROR 0x0100
#define TRANMERC_LON_WARNING 0x0200

class TranMerc {
  public:
  
  private:

};
/**
 * \brief Set the Transverse Mercator Parameters object
 *
 * \param a input Semi-major axis of ellipsoid, in meters
 * \param f input Flattening of ellipsoid
 * \param origin_latitude input Latitude in radians at the origin of the
 * projection \param central_meridian input Longitude in radians at the center
 * of the projection \param false_easting input Easting/X at the center of the
 * projection \param false_northing input Northing/Y at the center of the
 * projection \param scale_factor input Projection scale factor \return long If
 * any errors occur, the error code(s) are returned otherwise TRANMERC_NO_ERROR
 */
long SetTranMercParams(double a, double f, double ori_latitude,
                       double central_meridian, double false_easting,
                       double false_northing, double scale_factor);

/**
 * \brief Get the Transverse Mercator Parameters object
 *
 * \param a output Semi-major axis of ellipsoid, in meters
 * \param f output Flattening of ellipsoid
 * \param origin_latitude output Latitude in radians at the origin of the
 * projection \param central_meridian output Longitude in radians at the center
 * of the projection \param false_easting output Easting/X at the center of the
 * projection \param false_northing output Northing/Y at the center of the
 * projection \param scale_factor output Projection scale factor
 */
void GetTranMercParams(double *a, double *f, double *origin_latitude,
                       double *central_meridian, double *false_easting,
                       double *false_northing, double *scale_factor);

/**
 * \brief LatLon to Transverse Mercator
 *
 * \param latitude input Latitude in radians
 * \param longitude input Longitude in radians
 * \param easting output Easting/X in meters
 * \param northing output Northing/Y in meters
 * \return long If any errors occur, the error code(s) are returned otherwise
 * TRANMERC_NO_ERROR
 */
long LatLonToTranMerc(double latitude, double longitude, double *easting,
                      double *northing);

/**
 * \brief Transverse Mercator to LatLon
 *
 * \param easting input Easting/X in meters
 * \param northing input Northing/Y in meters
 * \param latitude output Latitude in radians
 * \param longitude output Longitude in radians
 * \return long If any errors occur, the error code(s) are returned otherwise
 * TRANMERC_NO_ERROR
 */
long TranMercToLatLon(double easting, double northing, double *latitude,
                      double *longitude);
#endif // TRANMERC_H